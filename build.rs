use cc::Build;
#[cfg(feature = "drivers")]
use std::collections::HashSet;
use std::{
    env,
    path::{Path, PathBuf},
};

static CONFIG_NAME: &str = "DEP_LV_CONFIG_PATH";

// See https://github.com/rust-lang/rust-bindgen/issues/687#issuecomment-450750547
#[cfg(feature = "drivers")]
#[derive(Debug)]
struct IgnoreMacros(HashSet<String>);
#[cfg(feature = "drivers")]
impl bindgen::callbacks::ParseCallbacks for IgnoreMacros {
    fn will_parse_macro(&self, name: &str) -> bindgen::callbacks::MacroParsingBehavior {
        if self.0.contains(name) {
            bindgen::callbacks::MacroParsingBehavior::Ignore
        } else {
            bindgen::callbacks::MacroParsingBehavior::Default
        }
    }
}

fn main() {
    let project_dir = canonicalize(PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap()));
    let shims_dir = project_dir.join("shims");
    let vendor = project_dir.join("vendor");
    let lvgl_src = project_dir.join("lvgl").join("src");

    #[cfg(feature = "rust_timer")]
    let timer_shim = vendor.join("include").join("timer");

    let font_extra_src: Option<PathBuf>;
    if let Ok(v) = env::var("PWD") {
        let current_dir = canonicalize(PathBuf::from(v));
        font_extra_src = {
            if let Ok(p) = env::var("LVGL_FONTS_DIR") {
                Some(canonicalize(PathBuf::from(p)))
            } else if current_dir.join("fonts").exists() {
                Some(current_dir.join("fonts"))
            } else {
                None
            }
        };
    } else {
        font_extra_src = None
    }

    // Some basic defaults; SDL2 is the only driver enabled in the provided
    // driver config by default
    #[cfg(feature = "drivers")]
    let incl_extra =
        env::var("LVGL_INCLUDE").unwrap_or("/usr/include,/usr/local/include".to_string());

    let cflags_extra_string = env::var("LVGL_CFLAGS").unwrap_or_default();

    let cflags_extra = if cflags_extra_string.is_empty() {
        None
    } else {
        Some(cflags_extra_string.split(','))
    };

    #[cfg(feature = "drivers")]
    let link_extra = env::var("LVGL_LINK").unwrap_or("SDL2".to_string());

    #[cfg(feature = "drivers")]
    let drivers = vendor.join("lv_drivers");

    let lv_config_dir = {
        let conf_path = env::var(CONFIG_NAME)
            .map(PathBuf::from)
            .unwrap_or_else(|_| {
                match std::env::var("DOCS_RS") {
                    Ok(_) => {
                        // We've detected that we are building for docs.rs
                        // so let's use the vendored `lv_conf.h` file.
                        vendor.join("include")
                    }
                    Err(_) => {
                        #[cfg(not(feature = "use-vendored-config"))]
                        panic!(
                            "The environment variable {} is required to be defined",
                            CONFIG_NAME
                        );

                        #[cfg(feature = "use-vendored-config")]
                        vendor.join("include")
                    }
                }
            });

        if !conf_path.exists() {
            panic!(
                "Directory {} referenced by {} needs to exist",
                conf_path.to_string_lossy(),
                CONFIG_NAME
            );
        }
        if !conf_path.is_dir() {
            panic!("{} needs to be a directory", CONFIG_NAME);
        }
        if !conf_path.join("lv_conf.h").exists() {
            panic!(
                "Directory {} referenced by {} needs to contain a file called lv_conf.h",
                conf_path.to_string_lossy(),
                CONFIG_NAME
            );
        }
        #[cfg(feature = "drivers")]
        if !conf_path.join("lv_drv_conf.h").exists() {
            panic!(
                "Directory {} referenced by {} needs to contain a file called lv_drv_conf.h",
                conf_path.to_string_lossy(),
                CONFIG_NAME
            );
        }

        if let Some(p) = &font_extra_src {
            println!("cargo:rerun-if-changed={}", p.to_str().unwrap())
        }

        println!(
            "cargo:rerun-if-changed={}",
            conf_path.join("lv_conf.h").to_str().unwrap()
        );
        #[cfg(feature = "drivers")]
        println!(
            "cargo:rerun-if-changed={}",
            conf_path.join("lv_drv_conf.h").to_str().unwrap()
        );
        conf_path
    };

    #[cfg(feature = "drivers")]
    {
        println!("cargo:rerun-if-env-changed=LVGL_INCLUDE");
        println!("cargo:rerun-if-env-changed=LVGL_LINK");
    }

    let mut cfg = Build::new();
    let target_str = env::var("TARGET").unwrap_or_default();
    if target_str.starts_with("xtensa-") {
        cfg.flag("-mlongcalls");
    }
    if let Some(p) = &font_extra_src {
        add_c_files(&mut cfg, p)
    }
    add_c_files(&mut cfg, &lvgl_src);
    add_c_files(&mut cfg, &lv_config_dir);
    add_c_files(&mut cfg, &shims_dir);
    #[cfg(feature = "drivers")]
    add_c_files(&mut cfg, &drivers);

    // For host (non-xtensa) builds, add SDL2 include path so LVGL's SDL driver compiles
    if !target_str.starts_with("xtensa-") {
        if let Ok(lib) = pkg_config::probe_library("sdl2") {
            for p in &lib.include_paths {
                cfg.include(p);
            }
        }
        println!("cargo:rustc-link-lib=SDL2");
    }

    cfg.define("LV_CONF_INCLUDE_SIMPLE", Some("1"))
        .include(&lvgl_src)
        .include(&vendor)
        .warnings(false)
        .include(&lv_config_dir);
    if let Some(p) = &font_extra_src {
        cfg.include(p);
    }
    #[cfg(feature = "rust_timer")]
    cfg.include(&timer_shim);
    #[cfg(feature = "drivers")]
    cfg.include(&drivers);
    #[cfg(feature = "drivers")]
    cfg.includes(incl_extra.split(','));

    if let Some(ref cflags_extra) = cflags_extra {
        cflags_extra.clone().for_each(|e| {
            let mut it = e.split('=');
            cfg.define(it.next().unwrap(), it.next().unwrap_or_default());
        });
    }

    let mut cc_args = vec![
        "-DLV_CONF_INCLUDE_SIMPLE=1",
        "-I",
        lv_config_dir.to_str().unwrap(),
        "-I",
        vendor.to_str().unwrap(),
        "-fvisibility=default",
    ];

    // Set correct target triple for bindgen when cross-compiling
    let target = env::var("TARGET").expect("Cargo build scripts always have TARGET");
    let host = env::var("HOST").expect("Cargo build scripts always have HOST");
    if target != host {
        cc_args.push("-target");
        cc_args.push(target.as_str());
    }

    let mut additional_args = Vec::new();
    // Add SDL2 include paths for bindgen on host builds
    if !target.starts_with("xtensa-") {
        if let Ok(lib) = pkg_config::probe_library("sdl2") {
            for p in &lib.include_paths {
                additional_args.push("-I".to_string());
                additional_args.push(p.to_str().unwrap().to_string());
            }
        }
    }
    if target.ends_with("emscripten") {
        match env::var("EMSDK") {
            Ok(em_path) =>
        {
            additional_args.push("-I".to_string());
            additional_args.push(format!(
                "{}/upstream/emscripten/system/include/libc",
                em_path
            ));
            additional_args.push("-I".to_string());
            additional_args.push(format!(
                "{}/upstream/emscripten/system/lib/libc/musl/arch/emscripten",
                em_path
            ));
            additional_args.push("-I".to_string());
            additional_args.push(format!(
                "{}/upstream/emscripten/system/include/SDL",
                em_path
            ));
        }
        Err(_) => panic!("The EMSDK environment variable is not set. Has emscripten been properly initialized?")
        }
    }

    #[cfg(feature = "drivers")]
    let ignored_macros = IgnoreMacros(
        vec![
            "FP_INFINITE".into(),
            "FP_NAN".into(),
            "FP_NORMAL".into(),
            "FP_SUBNORMAL".into(),
            "FP_ZERO".into(),
            "IPPORT_RESERVED".into(),
        ]
        .into_iter()
        .collect(),
    );

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    let bindings =
        bindgen::Builder::default()
            .header(shims_dir.join("lvgl_sys.h").to_str().unwrap());
    let bindings = add_font_headers(bindings, &font_extra_src);
    #[cfg(feature = "drivers")]
    let bindings = bindings
        .header(shims_dir.join("lvgl_drv.h").to_str().unwrap())
        .parse_callbacks(Box::new(ignored_macros));
    #[cfg(feature = "rust_timer")]
    let bindings = bindings.header(shims_dir.join("rs_timer.h").to_str().unwrap());

    let extra_clang_args: Vec<String> = env::var("BINDGEN_EXTRA_CLANG_ARGS")
        .unwrap_or_default()
        .split_whitespace()
        .map(str::to_owned)
        .collect();

    let bindings = bindings
        .generate_comments(false)
        .derive_default(true)
        .layout_tests(false)
        .use_core()
        .ctypes_prefix("core::ffi")
        .clang_args(&cc_args)
        .clang_args(&additional_args)
        .clang_args(
            cflags_extra
                .map(|s| s.collect::<Vec<_>>())
                .unwrap_or(Vec::new()),
        )
        .clang_args(&extra_clang_args)
        .wrap_static_fns(true)
        .wrap_static_fns_path(out_path.join("static_fns.c"))
        .generate()
        .expect("Unable to generate bindings");

    let bindings_path = out_path.join("bindings.rs");
    bindings
        .write_to_file(&bindings_path)
        .expect("Can't write bindings!");

    // bindgen 0.72 emits `transmute` for signed↔unsigned bitfield casts;
    // newer rustc warns (unnecessary_transmutes). Patch to use direct casts.
    fix_bindgen_transmutes(&bindings_path);

    cfg.file(out_path.join("static_fns.c"));
    cfg.compile("lvgl");

    #[cfg(feature = "drivers")]
    link_extra.split(',').for_each(|a| {
        println!("cargo:rustc-link-lib={a}");
        //println!("cargo:rustc-link-search=")
    })
}

fn add_font_headers(
    bindings: bindgen::Builder,
    dir: &Option<impl AsRef<Path>>,
) -> bindgen::Builder {
    if let Some(p) = dir {
        let mut temp = bindings;
        for e in p.as_ref().read_dir().unwrap() {
            let e = e.unwrap();
            let path = e.path();
            if !e.file_type().unwrap().is_dir()
                && path.extension().and_then(|s| s.to_str()) == Some("h")
            {
                temp = temp.header(path.to_str().unwrap());
            }
        }
        temp
    } else {
        bindings
    }
}

fn add_c_files(build: &mut cc::Build, path: impl AsRef<Path>) {
    for e in path.as_ref().read_dir().unwrap() {
        let e = e.unwrap();
        let path = e.path();
        if e.file_type().unwrap().is_dir() {
            add_c_files(build, e.path());
        } else if path.extension().and_then(|s| s.to_str()) == Some("c") {
            build.file(&path);
        }
    }
}

/// Replace unnecessary `transmute` calls in bindgen bitfield accessors and
/// strip `unsafe` blocks that become safe after removal.
/// bindgen 0.72 uses transmute for integer casts that rustc now warns about.
fn fix_bindgen_transmutes(path: &Path) {
    let mut code = std::fs::read_to_string(path).unwrap();

    // Phase 1: Replace `::core::mem::transmute(INNER)` → `(INNER) as _`.
    // Uses paren-matching to handle multi-line expressions.
    let needle = "::core::mem::transmute(";
    while let Some(start) = code.find(needle) {
        let inner_start = start + needle.len();
        let mut depth: u32 = 1;
        let mut end = inner_start;
        for ch in code[inner_start..].chars() {
            match ch {
                '(' => depth += 1,
                ')' => {
                    depth -= 1;
                    if depth == 0 {
                        break;
                    }
                }
                _ => {}
            }
            end += ch.len_utf8();
        }
        let inner = code[inner_start..end].to_string();
        let replacement = format!("({}) as _", inner);
        code = format!("{}{}{}", &code[..start], replacement, &code[end + 1..]);
    }

    // Phase 2: Strip `unsafe { ... }` blocks that no longer contain unsafe ops.
    // Keep blocks containing `raw_get`, `raw_set`, or `addr_of` (raw-pointer ops).
    let unsafe_kw = "unsafe {";
    let mut result = String::with_capacity(code.len());
    let mut pos = 0;
    let bytes = code.as_bytes();
    while pos < code.len() {
        if let Some(rel) = code[pos..].find(unsafe_kw) {
            let block_start = pos + rel;
            let brace_start = block_start + unsafe_kw.len() - 1; // position of '{'
            // Find matching '}'
            let mut depth: u32 = 1;
            let mut end = brace_start + 1;
            while end < code.len() && depth > 0 {
                match bytes[end] {
                    b'{' => depth += 1,
                    b'}' => depth -= 1,
                    _ => {}
                }
                end += 1;
            }
            let body = &code[brace_start + 1..end - 1]; // between { and }
            // Only strip unsafe from blocks whose body is purely safe after
            // transmute removal: bitfield get/set and simple casts.
            let is_safe_body = !body.contains("unsafe")
                && !body.contains("raw_get")
                && !body.contains("raw_set")
                && !body.contains("addr_of")
                && !body.contains("write_bytes")
                && !body.contains("assume_init")
                && !body.contains("from_raw")
                && !body.contains("as_ptr")
                && !body.contains("read_unaligned")
                && !body.contains("write_unaligned")
                && !body.contains("copy_nonoverlapping")
                && (body.contains("_bitfield_1") || body.contains("as _"));
            let needs_unsafe = !is_safe_body;

            // Copy text before `unsafe`
            result.push_str(&code[pos..block_start]);

            if needs_unsafe {
                // Keep the entire `unsafe { ... }` block
                result.push_str(&code[block_start..end]);
            } else {
                // Strip `unsafe { }`, keep the body with adjusted whitespace.
                // Single-line: `unsafe { EXPR }` → `EXPR`
                // Multi-line: preserve inner indentation as-is.
                let trimmed = body.trim();
                if !body.contains('\n') {
                    result.push_str(trimmed);
                } else {
                    result.push_str(body);
                }
            }
            pos = end;
        } else {
            result.push_str(&code[pos..]);
            break;
        }
    }

    std::fs::write(path, result).unwrap();
}

fn canonicalize(path: impl AsRef<Path>) -> PathBuf {
    let canonicalized = path.as_ref().canonicalize().unwrap();
    let canonicalized = &*canonicalized.to_string_lossy();

    PathBuf::from(canonicalized.strip_prefix(r"\\?\").unwrap_or(canonicalized))
}
