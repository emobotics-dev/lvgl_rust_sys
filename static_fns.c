#include "/home/holger-local/syncthing/projects/emobotics/alternator/alternator-regulator/lvgl_rust_sys/shims/lvgl_sys.h"

// Static wrappers

uint32_t lv_timer_handler_run_in_period__extern(uint32_t ms) { return lv_timer_handler_run_in_period(ms); }
int16_t lv_trigo_cos__extern(int16_t angle) { return lv_trigo_cos(angle); }
void * lv_memcpy_small__extern(void *dst, const void *src, size_t len) { return lv_memcpy_small(dst, src, len); }
void lv_anim_set_var__extern(lv_anim_t *a, void *var) { lv_anim_set_var(a, var); }
void lv_anim_set_exec_cb__extern(lv_anim_t *a, lv_anim_exec_xcb_t exec_cb) { lv_anim_set_exec_cb(a, exec_cb); }
void lv_anim_set_time__extern(lv_anim_t *a, uint32_t duration) { lv_anim_set_time(a, duration); }
void lv_anim_set_delay__extern(lv_anim_t *a, uint32_t delay) { lv_anim_set_delay(a, delay); }
void lv_anim_set_values__extern(lv_anim_t *a, int32_t start, int32_t end) { lv_anim_set_values(a, start, end); }
void lv_anim_set_custom_exec_cb__extern(lv_anim_t *a, lv_anim_custom_exec_cb_t exec_cb) { lv_anim_set_custom_exec_cb(a, exec_cb); }
void lv_anim_set_path_cb__extern(lv_anim_t *a, lv_anim_path_cb_t path_cb) { lv_anim_set_path_cb(a, path_cb); }
void lv_anim_set_start_cb__extern(lv_anim_t *a, lv_anim_start_cb_t start_cb) { lv_anim_set_start_cb(a, start_cb); }
void lv_anim_set_get_value_cb__extern(lv_anim_t *a, lv_anim_get_value_cb_t get_value_cb) { lv_anim_set_get_value_cb(a, get_value_cb); }
void lv_anim_set_ready_cb__extern(lv_anim_t *a, lv_anim_ready_cb_t ready_cb) { lv_anim_set_ready_cb(a, ready_cb); }
void lv_anim_set_deleted_cb__extern(lv_anim_t *a, lv_anim_deleted_cb_t deleted_cb) { lv_anim_set_deleted_cb(a, deleted_cb); }
void lv_anim_set_playback_time__extern(lv_anim_t *a, uint32_t time) { lv_anim_set_playback_time(a, time); }
void lv_anim_set_playback_delay__extern(lv_anim_t *a, uint32_t delay) { lv_anim_set_playback_delay(a, delay); }
void lv_anim_set_repeat_count__extern(lv_anim_t *a, uint16_t cnt) { lv_anim_set_repeat_count(a, cnt); }
void lv_anim_set_repeat_delay__extern(lv_anim_t *a, uint32_t delay) { lv_anim_set_repeat_delay(a, delay); }
void lv_anim_set_early_apply__extern(lv_anim_t *a, bool en) { lv_anim_set_early_apply(a, en); }
void lv_anim_set_user_data__extern(lv_anim_t *a, void *user_data) { lv_anim_set_user_data(a, user_data); }
uint32_t lv_anim_get_delay__extern(lv_anim_t *a) { return lv_anim_get_delay(a); }
void * lv_anim_get_user_data__extern(lv_anim_t *a) { return lv_anim_get_user_data(a); }
bool lv_anim_custom_del__extern(lv_anim_t *a, lv_anim_custom_exec_cb_t exec_cb) { return lv_anim_custom_del(a, exec_cb); }
lv_anim_t * lv_anim_custom_get__extern(lv_anim_t *a, lv_anim_custom_exec_cb_t exec_cb) { return lv_anim_custom_get(a, exec_cb); }
void lv_area_copy__extern(lv_area_t *dest, const lv_area_t *src) { lv_area_copy(dest, src); }
lv_coord_t lv_area_get_width__extern(const lv_area_t *area_p) { return lv_area_get_width(area_p); }
lv_coord_t lv_area_get_height__extern(const lv_area_t *area_p) { return lv_area_get_height(area_p); }
lv_coord_t lv_pct__extern(lv_coord_t x) { return lv_pct(x); }
lv_coord_t lv_font_get_line_height__extern(const lv_font_t *font_p) { return lv_font_get_line_height(font_p); }
const lv_font_t * lv_font_default__extern(void) { return lv_font_default(); }
uint8_t lv_color_to1__extern(lv_color_t color) { return lv_color_to1(color); }
uint8_t lv_color_to8__extern(lv_color_t color) { return lv_color_to8(color); }
uint16_t lv_color_to16__extern(lv_color_t color) { return lv_color_to16(color); }
uint32_t lv_color_to32__extern(lv_color_t color) { return lv_color_to32(color); }
lv_color_t lv_color_mix__extern(lv_color_t c1, lv_color_t c2, uint8_t mix) { return lv_color_mix(c1, c2, mix); }
void lv_color_premult__extern(lv_color_t c, uint8_t mix, uint16_t *out) { lv_color_premult(c, mix, out); }
lv_color_t lv_color_mix_premult__extern(uint16_t *premult_c1, lv_color_t c2, uint8_t mix) { return lv_color_mix_premult(premult_c1, c2, mix); }
void lv_color_mix_with_alpha__extern(lv_color_t bg_color, lv_opa_t bg_opa, lv_color_t fg_color, lv_opa_t fg_opa, lv_color_t *res_color, lv_opa_t *res_opa) { lv_color_mix_with_alpha(bg_color, bg_opa, fg_color, fg_opa, res_color, res_opa); }
uint8_t lv_color_brightness__extern(lv_color_t color) { return lv_color_brightness(color); }
lv_color_t lv_color_make__extern(uint8_t r, uint8_t g, uint8_t b) { return lv_color_make(r, g, b); }
lv_color_t lv_color_hex__extern(uint32_t c) { return lv_color_hex(c); }
lv_color_t lv_color_hex3__extern(uint32_t c) { return lv_color_hex3(c); }
void lv_color_filter_dsc_init__extern(lv_color_filter_dsc_t *dsc, lv_color_filter_cb_t cb) { lv_color_filter_dsc_init(dsc, cb); }
lv_color_t lv_color_chroma_key__extern(void) { return lv_color_chroma_key(); }
lv_color_t lv_color_white__extern(void) { return lv_color_white(); }
lv_color_t lv_color_black__extern(void) { return lv_color_black(); }
bool _lv_txt_is_break_char__extern(uint32_t letter) { return _lv_txt_is_break_char(letter); }
void lv_bidi_calculate_align__extern(lv_text_align_t *align, lv_base_dir_t *base_dir, const char *txt) { lv_bidi_calculate_align(align, base_dir, txt); }
lv_style_res_t lv_style_get_prop_inlined__extern(const lv_style_t *style, lv_style_prop_t prop, lv_style_value_t *value) { return lv_style_get_prop_inlined(style, prop, value); }
void lv_style_set_size__extern(lv_style_t *style, lv_coord_t value) { lv_style_set_size(style, value); }
void lv_style_set_pad_all__extern(lv_style_t *style, lv_coord_t value) { lv_style_set_pad_all(style, value); }
void lv_style_set_pad_hor__extern(lv_style_t *style, lv_coord_t value) { lv_style_set_pad_hor(style, value); }
void lv_style_set_pad_ver__extern(lv_style_t *style, lv_coord_t value) { lv_style_set_pad_ver(style, value); }
void lv_style_set_pad_gap__extern(lv_style_t *style, lv_coord_t value) { lv_style_set_pad_gap(style, value); }
bool lv_style_prop_has_flag__extern(lv_style_prop_t prop, uint8_t flag) { return lv_style_prop_has_flag(prop, flag); }
void lv_obj_center__extern(struct _lv_obj_t *obj) { lv_obj_center(obj); }
void lv_obj_remove_style_all__extern(struct _lv_obj_t *obj) { lv_obj_remove_style_all(obj); }
lv_coord_t lv_obj_get_style_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_width(obj, part); }
lv_coord_t lv_obj_get_style_min_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_min_width(obj, part); }
lv_coord_t lv_obj_get_style_max_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_max_width(obj, part); }
lv_coord_t lv_obj_get_style_height__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_height(obj, part); }
lv_coord_t lv_obj_get_style_min_height__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_min_height(obj, part); }
lv_coord_t lv_obj_get_style_max_height__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_max_height(obj, part); }
lv_coord_t lv_obj_get_style_x__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_x(obj, part); }
lv_coord_t lv_obj_get_style_y__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_y(obj, part); }
lv_align_t lv_obj_get_style_align__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_align(obj, part); }
lv_coord_t lv_obj_get_style_transform_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transform_width(obj, part); }
lv_coord_t lv_obj_get_style_transform_height__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transform_height(obj, part); }
lv_coord_t lv_obj_get_style_translate_x__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_translate_x(obj, part); }
lv_coord_t lv_obj_get_style_translate_y__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_translate_y(obj, part); }
lv_coord_t lv_obj_get_style_transform_zoom__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transform_zoom(obj, part); }
lv_coord_t lv_obj_get_style_transform_angle__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transform_angle(obj, part); }
lv_coord_t lv_obj_get_style_transform_pivot_x__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transform_pivot_x(obj, part); }
lv_coord_t lv_obj_get_style_transform_pivot_y__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transform_pivot_y(obj, part); }
lv_coord_t lv_obj_get_style_pad_top__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_pad_top(obj, part); }
lv_coord_t lv_obj_get_style_pad_bottom__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_pad_bottom(obj, part); }
lv_coord_t lv_obj_get_style_pad_left__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_pad_left(obj, part); }
lv_coord_t lv_obj_get_style_pad_right__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_pad_right(obj, part); }
lv_coord_t lv_obj_get_style_pad_row__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_pad_row(obj, part); }
lv_coord_t lv_obj_get_style_pad_column__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_pad_column(obj, part); }
lv_color_t lv_obj_get_style_bg_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_color(obj, part); }
lv_color_t lv_obj_get_style_bg_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_color_filtered(obj, part); }
lv_opa_t lv_obj_get_style_bg_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_opa(obj, part); }
lv_color_t lv_obj_get_style_bg_grad_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_grad_color(obj, part); }
lv_color_t lv_obj_get_style_bg_grad_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_grad_color_filtered(obj, part); }
lv_grad_dir_t lv_obj_get_style_bg_grad_dir__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_grad_dir(obj, part); }
lv_coord_t lv_obj_get_style_bg_main_stop__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_main_stop(obj, part); }
lv_coord_t lv_obj_get_style_bg_grad_stop__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_grad_stop(obj, part); }
const lv_grad_dsc_t * lv_obj_get_style_bg_grad__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_grad(obj, part); }
lv_dither_mode_t lv_obj_get_style_bg_dither_mode__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_dither_mode(obj, part); }
const void * lv_obj_get_style_bg_img_src__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_img_src(obj, part); }
lv_opa_t lv_obj_get_style_bg_img_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_img_opa(obj, part); }
lv_color_t lv_obj_get_style_bg_img_recolor__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_img_recolor(obj, part); }
lv_color_t lv_obj_get_style_bg_img_recolor_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_img_recolor_filtered(obj, part); }
lv_opa_t lv_obj_get_style_bg_img_recolor_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_img_recolor_opa(obj, part); }
bool lv_obj_get_style_bg_img_tiled__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_bg_img_tiled(obj, part); }
lv_color_t lv_obj_get_style_border_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_border_color(obj, part); }
lv_color_t lv_obj_get_style_border_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_border_color_filtered(obj, part); }
lv_opa_t lv_obj_get_style_border_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_border_opa(obj, part); }
lv_coord_t lv_obj_get_style_border_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_border_width(obj, part); }
lv_border_side_t lv_obj_get_style_border_side__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_border_side(obj, part); }
bool lv_obj_get_style_border_post__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_border_post(obj, part); }
lv_coord_t lv_obj_get_style_outline_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_outline_width(obj, part); }
lv_color_t lv_obj_get_style_outline_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_outline_color(obj, part); }
lv_color_t lv_obj_get_style_outline_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_outline_color_filtered(obj, part); }
lv_opa_t lv_obj_get_style_outline_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_outline_opa(obj, part); }
lv_coord_t lv_obj_get_style_outline_pad__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_outline_pad(obj, part); }
lv_coord_t lv_obj_get_style_shadow_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_shadow_width(obj, part); }
lv_coord_t lv_obj_get_style_shadow_ofs_x__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_shadow_ofs_x(obj, part); }
lv_coord_t lv_obj_get_style_shadow_ofs_y__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_shadow_ofs_y(obj, part); }
lv_coord_t lv_obj_get_style_shadow_spread__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_shadow_spread(obj, part); }
lv_color_t lv_obj_get_style_shadow_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_shadow_color(obj, part); }
lv_color_t lv_obj_get_style_shadow_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_shadow_color_filtered(obj, part); }
lv_opa_t lv_obj_get_style_shadow_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_shadow_opa(obj, part); }
lv_opa_t lv_obj_get_style_img_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_img_opa(obj, part); }
lv_color_t lv_obj_get_style_img_recolor__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_img_recolor(obj, part); }
lv_color_t lv_obj_get_style_img_recolor_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_img_recolor_filtered(obj, part); }
lv_opa_t lv_obj_get_style_img_recolor_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_img_recolor_opa(obj, part); }
lv_coord_t lv_obj_get_style_line_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_line_width(obj, part); }
lv_coord_t lv_obj_get_style_line_dash_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_line_dash_width(obj, part); }
lv_coord_t lv_obj_get_style_line_dash_gap__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_line_dash_gap(obj, part); }
bool lv_obj_get_style_line_rounded__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_line_rounded(obj, part); }
lv_color_t lv_obj_get_style_line_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_line_color(obj, part); }
lv_color_t lv_obj_get_style_line_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_line_color_filtered(obj, part); }
lv_opa_t lv_obj_get_style_line_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_line_opa(obj, part); }
lv_coord_t lv_obj_get_style_arc_width__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_arc_width(obj, part); }
bool lv_obj_get_style_arc_rounded__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_arc_rounded(obj, part); }
lv_color_t lv_obj_get_style_arc_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_arc_color(obj, part); }
lv_color_t lv_obj_get_style_arc_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_arc_color_filtered(obj, part); }
lv_opa_t lv_obj_get_style_arc_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_arc_opa(obj, part); }
const void * lv_obj_get_style_arc_img_src__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_arc_img_src(obj, part); }
lv_color_t lv_obj_get_style_text_color__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_color(obj, part); }
lv_color_t lv_obj_get_style_text_color_filtered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_color_filtered(obj, part); }
lv_opa_t lv_obj_get_style_text_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_opa(obj, part); }
const lv_font_t * lv_obj_get_style_text_font__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_font(obj, part); }
lv_coord_t lv_obj_get_style_text_letter_space__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_letter_space(obj, part); }
lv_coord_t lv_obj_get_style_text_line_space__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_line_space(obj, part); }
lv_text_decor_t lv_obj_get_style_text_decor__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_decor(obj, part); }
lv_text_align_t lv_obj_get_style_text_align__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_text_align(obj, part); }
lv_coord_t lv_obj_get_style_radius__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_radius(obj, part); }
bool lv_obj_get_style_clip_corner__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_clip_corner(obj, part); }
lv_opa_t lv_obj_get_style_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_opa(obj, part); }
lv_opa_t lv_obj_get_style_opa_layered__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_opa_layered(obj, part); }
const lv_color_filter_dsc_t * lv_obj_get_style_color_filter_dsc__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_color_filter_dsc(obj, part); }
lv_opa_t lv_obj_get_style_color_filter_opa__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_color_filter_opa(obj, part); }
const lv_anim_t * lv_obj_get_style_anim__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_anim(obj, part); }
uint32_t lv_obj_get_style_anim_time__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_anim_time(obj, part); }
uint32_t lv_obj_get_style_anim_speed__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_anim_speed(obj, part); }
const lv_style_transition_dsc_t * lv_obj_get_style_transition__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transition(obj, part); }
lv_blend_mode_t lv_obj_get_style_blend_mode__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_blend_mode(obj, part); }
uint16_t lv_obj_get_style_layout__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_layout(obj, part); }
lv_base_dir_t lv_obj_get_style_base_dir__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_base_dir(obj, part); }
void lv_obj_set_style_pad_all__extern(struct _lv_obj_t *obj, lv_coord_t value, lv_style_selector_t selector) { lv_obj_set_style_pad_all(obj, value, selector); }
void lv_obj_set_style_pad_hor__extern(struct _lv_obj_t *obj, lv_coord_t value, lv_style_selector_t selector) { lv_obj_set_style_pad_hor(obj, value, selector); }
void lv_obj_set_style_pad_ver__extern(struct _lv_obj_t *obj, lv_coord_t value, lv_style_selector_t selector) { lv_obj_set_style_pad_ver(obj, value, selector); }
void lv_obj_set_style_pad_gap__extern(struct _lv_obj_t *obj, lv_coord_t value, lv_style_selector_t selector) { lv_obj_set_style_pad_gap(obj, value, selector); }
void lv_obj_set_style_size__extern(struct _lv_obj_t *obj, lv_coord_t value, lv_style_selector_t selector) { lv_obj_set_style_size(obj, value, selector); }
lv_coord_t lv_obj_get_style_transform_zoom_safe__extern(const struct _lv_obj_t *obj, uint32_t part) { return lv_obj_get_style_transform_zoom_safe(obj, part); }
void lv_obj_set_user_data__extern(lv_obj_t *obj, void *user_data) { lv_obj_set_user_data(obj, user_data); }
void * lv_obj_get_user_data__extern(lv_obj_t *obj) { return lv_obj_get_user_data(obj); }
lv_coord_t lv_obj_dpx__extern(const lv_obj_t *obj, lv_coord_t n) { return lv_obj_dpx(obj, n); }
lv_obj_t * lv_scr_act__extern(void) { return lv_scr_act(); }
lv_obj_t * lv_layer_top__extern(void) { return lv_layer_top(); }
lv_obj_t * lv_layer_sys__extern(void) { return lv_layer_sys(); }
void lv_scr_load__extern(lv_obj_t *scr) { lv_scr_load(scr); }
lv_coord_t lv_dpx__extern(lv_coord_t n) { return lv_dpx(n); }
lv_coord_t lv_disp_dpx__extern(const lv_disp_t *disp, lv_coord_t n) { return lv_disp_dpx(disp, n); }
uint32_t lv_task_handler__extern(void) { return lv_task_handler(); }
void lv_obj_move_foreground__extern(lv_obj_t *obj) { lv_obj_move_foreground(obj); }
void lv_obj_move_background__extern(lv_obj_t *obj) { lv_obj_move_background(obj); }
uint32_t lv_obj_get_child_id__extern(const struct _lv_obj_t *obj) { return lv_obj_get_child_id(obj); }
int lv_version_major__extern(void) { return lv_version_major(); }
int lv_version_minor__extern(void) { return lv_version_minor(); }
int lv_version_patch__extern(void) { return lv_version_patch(); }
const char * lv_version_info__extern(void) { return lv_version_info(); }
