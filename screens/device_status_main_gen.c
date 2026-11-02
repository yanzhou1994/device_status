/**
 * @file device_status_main_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "device_status_main_gen.h"
#include "../device_status.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * device_status_main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t card;
    static lv_style_t plain;
    static lv_style_t dot;
    static lv_style_t btn_on;
    static lv_style_t btn_off;
    static lv_style_t badge;
    static lv_style_t seg_track;
    static lv_style_t seg_active;
    static lv_style_t divider;
    static lv_style_t hline;
    static lv_style_t arc_track;
    static lv_style_t arc_ind;
    static lv_style_t arc_knob;
    static lv_style_t bar_track;
    static lv_style_t bar_ind;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&card);
        lv_style_init(&plain);
        lv_style_init(&dot);
        lv_style_init(&btn_on);
        lv_style_init(&btn_off);
        lv_style_init(&badge);
        lv_style_init(&seg_track);
        lv_style_init(&seg_active);
        lv_style_init(&divider);
        lv_style_init(&hline);
        lv_style_init(&arc_track);
        lv_style_init(&arc_ind);
        lv_style_init(&arc_knob);
        lv_style_init(&bar_track);
        lv_style_init(&bar_ind);

        lv_style_set_bg_color(&card, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&card, (255 * 100 / 100));
        lv_style_set_radius(&card, 12);
        lv_style_set_border_width(&card, 0);
        lv_style_set_pad_all(&card, 0);
        lv_style_set_shadow_color(&card, lv_color_hex(0x8c99a6));
        lv_style_set_shadow_width(&card, 18);
        lv_style_set_shadow_opa(&card, (255 * 15 / 100));
        lv_style_set_shadow_offset_y(&card, 4);
        lv_style_set_shadow_spread(&card, -2);
        lv_style_set_bg_opa(&plain, (255 * 0 / 100));
        lv_style_set_border_width(&plain, 0);
        lv_style_set_radius(&plain, 0);
        lv_style_set_pad_all(&plain, 0);
        lv_style_set_radius(&dot, 999);
        lv_style_set_border_width(&dot, 0);
        lv_style_set_pad_all(&dot, 0);
        lv_style_set_bg_color(&btn_on, lv_color_hex(0x16a6a1));
        lv_style_set_bg_opa(&btn_on, (255 * 100 / 100));
        lv_style_set_radius(&btn_on, 6);
        lv_style_set_border_width(&btn_on, 0);
        lv_style_set_shadow_width(&btn_on, 0);
        lv_style_set_bg_color(&btn_off, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&btn_off, (255 * 100 / 100));
        lv_style_set_radius(&btn_off, 6);
        lv_style_set_border_width(&btn_off, 1);
        lv_style_set_border_color(&btn_off, lv_color_hex(0xeaedf0));
        lv_style_set_shadow_width(&btn_off, 0);
        lv_style_set_radius(&badge, 4);
        lv_style_set_border_width(&badge, 0);
        lv_style_set_pad_all(&badge, 0);
        lv_style_set_bg_color(&seg_track, lv_color_hex(0xedeef1));
        lv_style_set_bg_opa(&seg_track, (255 * 100 / 100));
        lv_style_set_radius(&seg_track, 999);
        lv_style_set_border_width(&seg_track, 0);
        lv_style_set_pad_all(&seg_track, 0);
        lv_style_set_bg_color(&seg_active, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&seg_active, (255 * 100 / 100));
        lv_style_set_radius(&seg_active, 999);
        lv_style_set_border_width(&seg_active, 0);
        lv_style_set_shadow_color(&seg_active, lv_color_hex(0x6b7683));
        lv_style_set_shadow_width(&seg_active, 6);
        lv_style_set_shadow_opa(&seg_active, (255 * 16 / 100));
        lv_style_set_shadow_offset_y(&seg_active, 1);
        lv_style_set_bg_color(&divider, lv_color_hex(0xeaedf0));
        lv_style_set_bg_opa(&divider, (255 * 100 / 100));
        lv_style_set_border_width(&divider, 0);
        lv_style_set_radius(&divider, 0);
        lv_style_set_pad_all(&divider, 0);
        lv_style_set_bg_color(&hline, lv_color_hex(0xf0f2f4));
        lv_style_set_bg_opa(&hline, (255 * 100 / 100));
        lv_style_set_border_width(&hline, 0);
        lv_style_set_radius(&hline, 0);
        lv_style_set_pad_all(&hline, 0);
        lv_style_set_arc_color(&arc_track, lv_color_hex(0xe9ecef));
        lv_style_set_arc_width(&arc_track, 6);
        lv_style_set_arc_rounded(&arc_track, true);
        lv_style_set_bg_opa(&arc_track, (255 * 0 / 100));
        lv_style_set_arc_color(&arc_ind, lv_color_hex(0x16a6a1));
        lv_style_set_arc_width(&arc_ind, 6);
        lv_style_set_arc_rounded(&arc_ind, true);
        lv_style_set_pad_all(&arc_ind, 0);
        lv_style_set_bg_opa(&arc_knob, (255 * 0 / 100));
        lv_style_set_border_width(&arc_knob, 0);
        lv_style_set_pad_all(&arc_knob, 0);
        lv_style_set_shadow_width(&arc_knob, 0);
        lv_style_set_bg_color(&bar_track, lv_color_hex(0xe9ecef));
        lv_style_set_bg_opa(&bar_track, (255 * 100 / 100));
        lv_style_set_radius(&bar_track, 999);
        lv_style_set_bg_color(&bar_ind, lv_color_hex(0x16a6a1));
        lv_style_set_bg_opa(&bar_ind, (255 * 100 / 100));
        lv_style_set_radius(&bar_ind, 999);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if DEVICE_STATUS_CHECK_COMPILE_TARGET(DEVICE_STATUS_TARGET_ALL)
    if (device_status_check_target(DEVICE_STATUS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "device_status_main_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xf2f4f6), 0);
        lv_obj_set_style_bg_opa(lv_obj_0, (255 * 100 / 100), 0);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_t * top_bar = lv_obj_create(lv_obj_0);
        lv_obj_set_flag(top_bar, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(top_bar, "top_bar");
        lv_obj_set_x(top_bar, 48);
        lv_obj_set_y(top_bar, 28);
        lv_obj_set_width(top_bar, 984);
        lv_obj_set_height(top_bar, 64);
        lv_obj_add_style(top_bar, &card, 0);
        lv_obj_t * title = lv_label_create(top_bar);
        lv_obj_set_name(title, "title");
        lv_obj_set_x(title, 20);
        lv_obj_set_y(title, 15);
        lv_label_set_text(title, "设备状态总览");
        lv_obj_set_style_text_font(title, font_title, 0);
        lv_obj_set_style_text_color(title, lv_color_hex(0x17191c), 0);

        lv_obj_t * time = lv_label_create(top_bar);
        lv_obj_set_name(time, "time");
        lv_obj_set_x(time, 196);
        lv_obj_set_y(time, 25);
        lv_label_set_text(time, "2026-11-02 14:32:08");
        lv_obj_set_style_text_font(time, font_small, 0);
        lv_obj_set_style_text_color(time, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * seg = lv_obj_create(top_bar);
        lv_obj_set_flag(seg, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(seg, "seg");
        lv_obj_set_align(seg, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(seg, -22);
        lv_obj_set_width(seg, 104);
        lv_obj_set_height(seg, 30);
        lv_obj_add_style(seg, &seg_track, 0);
        lv_obj_t * seg_pill = lv_obj_create(seg);
        lv_obj_set_flag(seg_pill, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(seg_pill, "seg_pill");
        lv_obj_set_x(seg_pill, 3);
        lv_obj_set_y(seg_pill, 2);
        lv_obj_set_width(seg_pill, 46);
        lv_obj_set_height(seg_pill, 26);
        lv_obj_add_style(seg_pill, &seg_active, 0);
        lv_obj_t * seg_pill_label = lv_label_create(seg_pill);
        lv_obj_set_name(seg_pill_label, "seg_pill_label");
        lv_obj_set_align(seg_pill_label, LV_ALIGN_CENTER);
        lv_label_set_text(seg_pill_label, "设备");
        lv_obj_set_style_text_font(seg_pill_label, font_body, 0);
        lv_obj_set_style_text_color(seg_pill_label, lv_color_hex(0x17191c), 0);

        lv_obj_t * seg_other_label = lv_label_create(seg);
        lv_obj_set_name(seg_other_label, "seg_other_label");
        lv_obj_set_align(seg_other_label, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(seg_other_label, -14);
        lv_label_set_text(seg_other_label, "趋势");
        lv_obj_set_style_text_font(seg_other_label, font_body, 0);
        lv_obj_set_style_text_color(seg_other_label, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * status_card = lv_obj_create(lv_obj_0);
        lv_obj_set_flag(status_card, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(status_card, "status_card");
        lv_obj_set_x(status_card, 48);
        lv_obj_set_y(status_card, 110);
        lv_obj_set_width(status_card, 452);
        lv_obj_set_height(status_card, 246);
        lv_obj_add_style(status_card, &card, 0);
        lv_obj_t * status_title = lv_label_create(status_card);
        lv_obj_set_name(status_title, "status_title");
        lv_obj_set_x(status_title, 20);
        lv_obj_set_y(status_title, 20);
        lv_label_set_text(status_title, "设备运行状态");
        lv_obj_set_style_text_font(status_title, font_h3, 0);
        lv_obj_set_style_text_color(status_title, lv_color_hex(0x17191c), 0);

        lv_obj_t * row_pump = lv_obj_create(status_card);
        lv_obj_set_flag(row_pump, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(row_pump, "row_pump");
        lv_obj_set_x(row_pump, 0);
        lv_obj_set_y(row_pump, 74);
        lv_obj_set_width(row_pump, 452);
        lv_obj_set_height(row_pump, 28);
        lv_obj_add_style(row_pump, &plain, 0);
        lv_obj_t * dot_pump = lv_obj_create(row_pump);
        lv_obj_set_flag(dot_pump, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(dot_pump, "dot_pump");
        lv_obj_set_x(dot_pump, 20);
        lv_obj_set_y(dot_pump, 7);
        lv_obj_set_width(dot_pump, 14);
        lv_obj_set_height(dot_pump, 14);
        lv_obj_set_style_bg_color(dot_pump, lv_color_hex(0x4fb745), 0);
        lv_obj_set_style_bg_opa(dot_pump, (255 * 100 / 100), 0);
        lv_obj_add_style(dot_pump, &dot, 0);

        lv_obj_t * name_pump = lv_label_create(row_pump);
        lv_obj_set_name(name_pump, "name_pump");
        lv_obj_set_x(name_pump, 46);
        lv_obj_set_y(name_pump, 5);
        lv_label_set_text(name_pump, "1#水泵");
        lv_obj_set_style_text_font(name_pump, font_body, 0);
        lv_obj_set_style_text_color(name_pump, lv_color_hex(0x4c5257), 0);

        lv_obj_t * state_pump = lv_label_create(row_pump);
        lv_obj_set_name(state_pump, "state_pump");
        lv_obj_set_align(state_pump, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(state_pump, -28);
        lv_label_set_text(state_pump, "运行中");
        lv_obj_set_style_text_font(state_pump, font_body, 0);
        lv_obj_set_style_text_color(state_pump, lv_color_hex(0x2f7fe0), 0);

        lv_obj_t * row_conv = lv_obj_create(status_card);
        lv_obj_set_flag(row_conv, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(row_conv, "row_conv");
        lv_obj_set_x(row_conv, 0);
        lv_obj_set_y(row_conv, 117);
        lv_obj_set_width(row_conv, 452);
        lv_obj_set_height(row_conv, 28);
        lv_obj_add_style(row_conv, &plain, 0);
        lv_obj_t * dot_conv = lv_obj_create(row_conv);
        lv_obj_set_flag(dot_conv, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(dot_conv, "dot_conv");
        lv_obj_set_x(dot_conv, 20);
        lv_obj_set_y(dot_conv, 7);
        lv_obj_set_width(dot_conv, 14);
        lv_obj_set_height(dot_conv, 14);
        lv_obj_set_style_bg_color(dot_conv, lv_color_hex(0xf5d42b), 0);
        lv_obj_set_style_bg_opa(dot_conv, (255 * 100 / 100), 0);
        lv_obj_add_style(dot_conv, &dot, 0);

        lv_obj_t * name_conv = lv_label_create(row_conv);
        lv_obj_set_name(name_conv, "name_conv");
        lv_obj_set_x(name_conv, 46);
        lv_obj_set_y(name_conv, 5);
        lv_label_set_text(name_conv, "23#传送带");
        lv_obj_set_style_text_font(name_conv, font_body, 0);
        lv_obj_set_style_text_color(name_conv, lv_color_hex(0x4c5257), 0);

        lv_obj_t * state_conv = lv_label_create(row_conv);
        lv_obj_set_name(state_conv, "state_conv");
        lv_obj_set_align(state_conv, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(state_conv, -28);
        lv_label_set_text(state_conv, "待机");
        lv_obj_set_style_text_font(state_conv, font_body, 0);
        lv_obj_set_style_text_color(state_conv, lv_color_hex(0xc9a227), 0);

        lv_obj_t * row_comp = lv_obj_create(status_card);
        lv_obj_set_flag(row_comp, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(row_comp, "row_comp");
        lv_obj_set_x(row_comp, 0);
        lv_obj_set_y(row_comp, 160);
        lv_obj_set_width(row_comp, 452);
        lv_obj_set_height(row_comp, 28);
        lv_obj_add_style(row_comp, &plain, 0);
        lv_obj_t * dot_comp = lv_obj_create(row_comp);
        lv_obj_set_flag(dot_comp, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(dot_comp, "dot_comp");
        lv_obj_set_x(dot_comp, 20);
        lv_obj_set_y(dot_comp, 7);
        lv_obj_set_width(dot_comp, 14);
        lv_obj_set_height(dot_comp, 14);
        lv_obj_set_style_bg_color(dot_comp, lv_color_hex(0xe23b2f), 0);
        lv_obj_set_style_bg_opa(dot_comp, (255 * 100 / 100), 0);
        lv_obj_add_style(dot_comp, &dot, 0);

        lv_obj_t * name_comp = lv_label_create(row_comp);
        lv_obj_set_name(name_comp, "name_comp");
        lv_obj_set_x(name_comp, 46);
        lv_obj_set_y(name_comp, 5);
        lv_label_set_text(name_comp, "4#压缩机");
        lv_obj_set_style_text_font(name_comp, font_body, 0);
        lv_obj_set_style_text_color(name_comp, lv_color_hex(0x4c5257), 0);

        lv_obj_t * state_comp = lv_label_create(row_comp);
        lv_obj_set_name(state_comp, "state_comp");
        lv_obj_set_align(state_comp, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(state_comp, -28);
        lv_label_set_text(state_comp, "运行中");
        lv_obj_set_style_text_font(state_comp, font_body, 0);
        lv_obj_set_style_text_color(state_comp, lv_color_hex(0x2f7fe0), 0);

        lv_obj_t * row_valve = lv_obj_create(status_card);
        lv_obj_set_flag(row_valve, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(row_valve, "row_valve");
        lv_obj_set_x(row_valve, 0);
        lv_obj_set_y(row_valve, 203);
        lv_obj_set_width(row_valve, 452);
        lv_obj_set_height(row_valve, 28);
        lv_obj_add_style(row_valve, &plain, 0);
        lv_obj_t * dot_valve = lv_obj_create(row_valve);
        lv_obj_set_flag(dot_valve, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(dot_valve, "dot_valve");
        lv_obj_set_x(dot_valve, 20);
        lv_obj_set_y(dot_valve, 7);
        lv_obj_set_width(dot_valve, 14);
        lv_obj_set_height(dot_valve, 14);
        lv_obj_set_style_bg_color(dot_valve, lv_color_hex(0xc2c6c9), 0);
        lv_obj_set_style_bg_opa(dot_valve, (255 * 100 / 100), 0);
        lv_obj_add_style(dot_valve, &dot, 0);

        lv_obj_t * name_valve = lv_label_create(row_valve);
        lv_obj_set_name(name_valve, "name_valve");
        lv_obj_set_x(name_valve, 46);
        lv_obj_set_y(name_valve, 5);
        lv_label_set_text(name_valve, "5#阀门");
        lv_obj_set_style_text_font(name_valve, font_body, 0);
        lv_obj_set_style_text_color(name_valve, lv_color_hex(0x4c5257), 0);

        lv_obj_t * state_valve = lv_label_create(row_valve);
        lv_obj_set_name(state_valve, "state_valve");
        lv_obj_set_align(state_valve, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(state_valve, -28);
        lv_label_set_text(state_valve, "离线");
        lv_obj_set_style_text_font(state_valve, font_body, 0);
        lv_obj_set_style_text_color(state_valve, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * sensor_card = lv_obj_create(lv_obj_0);
        lv_obj_set_flag(sensor_card, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(sensor_card, "sensor_card");
        lv_obj_set_x(sensor_card, 520);
        lv_obj_set_y(sensor_card, 110);
        lv_obj_set_width(sensor_card, 512);
        lv_obj_set_height(sensor_card, 246);
        lv_obj_add_style(sensor_card, &card, 0);
        lv_obj_t * sensor_title = lv_label_create(sensor_card);
        lv_obj_set_name(sensor_title, "sensor_title");
        lv_obj_set_x(sensor_title, 20);
        lv_obj_set_y(sensor_title, 20);
        lv_label_set_text(sensor_title, "温湿度传感器数据");
        lv_obj_set_style_text_font(sensor_title, font_h3, 0);
        lv_obj_set_style_text_color(sensor_title, lv_color_hex(0x17191c), 0);

        lv_obj_t * arc_temp = lv_arc_create(sensor_card);
        lv_obj_set_name(arc_temp, "arc_temp");
        lv_obj_set_x(arc_temp, 14);
        lv_obj_set_y(arc_temp, 74);
        lv_obj_set_width(arc_temp, 132);
        lv_obj_set_height(arc_temp, 132);
        lv_arc_set_rotation(arc_temp, 270);
        lv_arc_set_bg_start_angle(arc_temp, 0);
        lv_arc_set_bg_end_angle(arc_temp, 360);
        lv_arc_set_min_value(arc_temp, 0);
        lv_arc_set_max_value(arc_temp, 100);
        lv_arc_set_value(arc_temp, 78);
        lv_obj_add_style(arc_temp, &arc_track, LV_PART_MAIN);
        lv_obj_add_style(arc_temp, &arc_ind, LV_PART_INDICATOR);
        lv_obj_add_style(arc_temp, &arc_knob, LV_PART_KNOB);
        lv_obj_t * cont_temp = lv_obj_create(arc_temp);
        lv_obj_set_flag(cont_temp, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(cont_temp, "cont_temp");
        lv_obj_set_align(cont_temp, LV_ALIGN_CENTER);
        lv_obj_set_width(cont_temp, 118);
        lv_obj_set_height(cont_temp, 70);
        lv_obj_add_style(cont_temp, &plain, 0);
        lv_obj_t * row_temp = lv_obj_create(cont_temp);
        lv_obj_set_flag(row_temp, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(row_temp, "row_temp");
        lv_obj_set_align(row_temp, LV_ALIGN_TOP_MID);
        lv_obj_set_width(row_temp, 118);
        lv_obj_set_height(row_temp, 34);
        lv_obj_set_flex_flow(row_temp, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(row_temp, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(row_temp, LV_FLEX_ALIGN_START, 0);
        lv_obj_set_style_pad_column(row_temp, 0, 0);
        lv_obj_add_style(row_temp, &plain, 0);
        lv_obj_t * val_temp = lv_label_create(row_temp);
        lv_obj_set_name(val_temp, "val_temp");
        lv_label_set_text(val_temp, "24.6");
        lv_obj_set_style_text_font(val_temp, font_value, 0);
        lv_obj_set_style_text_color(val_temp, lv_color_hex(0x16a6a1), 0);

        lv_obj_t * unit_temp = lv_label_create(row_temp);
        lv_obj_set_name(unit_temp, "unit_temp");
        lv_label_set_text(unit_temp, "℃");
        lv_obj_set_style_text_font(unit_temp, font_small, 0);
        lv_obj_set_style_text_color(unit_temp, lv_color_hex(0x16a6a1), 0);

        lv_obj_t * cap_temp = lv_label_create(cont_temp);
        lv_obj_set_name(cap_temp, "cap_temp");
        lv_obj_set_align(cap_temp, LV_ALIGN_TOP_MID);
        lv_obj_set_y(cap_temp, 34);
        lv_label_set_text(cap_temp, "温度");
        lv_obj_set_style_text_font(cap_temp, font_small, 0);
        lv_obj_set_style_text_color(cap_temp, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * bar_temp = lv_bar_create(cont_temp);
        lv_obj_set_name(bar_temp, "bar_temp");
        lv_obj_set_align(bar_temp, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_width(bar_temp, 74);
        lv_obj_set_height(bar_temp, 4);
        lv_bar_set_min_value(bar_temp, 0);
        lv_bar_set_max_value(bar_temp, 100);
        lv_bar_set_value(bar_temp, 55, false);
        lv_obj_add_style(bar_temp, &bar_track, LV_PART_MAIN);
        lv_obj_add_style(bar_temp, &bar_ind, LV_PART_INDICATOR);

        lv_obj_t * arc_humi = lv_arc_create(sensor_card);
        lv_obj_set_name(arc_humi, "arc_humi");
        lv_obj_set_x(arc_humi, 204);
        lv_obj_set_y(arc_humi, 74);
        lv_obj_set_width(arc_humi, 132);
        lv_obj_set_height(arc_humi, 132);
        lv_arc_set_rotation(arc_humi, 270);
        lv_arc_set_bg_start_angle(arc_humi, 0);
        lv_arc_set_bg_end_angle(arc_humi, 360);
        lv_arc_set_min_value(arc_humi, 0);
        lv_arc_set_max_value(arc_humi, 100);
        lv_arc_set_value(arc_humi, 72);
        lv_obj_add_style(arc_humi, &arc_track, LV_PART_MAIN);
        lv_obj_add_style(arc_humi, &arc_ind, LV_PART_INDICATOR);
        lv_obj_add_style(arc_humi, &arc_knob, LV_PART_KNOB);
        lv_obj_t * cont_humi = lv_obj_create(arc_humi);
        lv_obj_set_flag(cont_humi, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(cont_humi, "cont_humi");
        lv_obj_set_align(cont_humi, LV_ALIGN_CENTER);
        lv_obj_set_width(cont_humi, 118);
        lv_obj_set_height(cont_humi, 70);
        lv_obj_add_style(cont_humi, &plain, 0);
        lv_obj_t * row_humi = lv_obj_create(cont_humi);
        lv_obj_set_flag(row_humi, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(row_humi, "row_humi");
        lv_obj_set_align(row_humi, LV_ALIGN_TOP_MID);
        lv_obj_set_width(row_humi, 118);
        lv_obj_set_height(row_humi, 34);
        lv_obj_set_flex_flow(row_humi, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(row_humi, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(row_humi, LV_FLEX_ALIGN_START, 0);
        lv_obj_set_style_pad_column(row_humi, 0, 0);
        lv_obj_add_style(row_humi, &plain, 0);
        lv_obj_t * val_humi = lv_label_create(row_humi);
        lv_obj_set_name(val_humi, "val_humi");
        lv_label_set_text(val_humi, "58");
        lv_obj_set_style_text_font(val_humi, font_value, 0);
        lv_obj_set_style_text_color(val_humi, lv_color_hex(0x16a6a1), 0);

        lv_obj_t * unit_humi = lv_label_create(row_humi);
        lv_obj_set_name(unit_humi, "unit_humi");
        lv_label_set_text(unit_humi, "%RH");
        lv_obj_set_style_text_font(unit_humi, font_small, 0);
        lv_obj_set_style_text_color(unit_humi, lv_color_hex(0x16a6a1), 0);

        lv_obj_t * cap_humi = lv_label_create(cont_humi);
        lv_obj_set_name(cap_humi, "cap_humi");
        lv_obj_set_align(cap_humi, LV_ALIGN_TOP_MID);
        lv_obj_set_y(cap_humi, 34);
        lv_label_set_text(cap_humi, "湿度");
        lv_obj_set_style_text_font(cap_humi, font_small, 0);
        lv_obj_set_style_text_color(cap_humi, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * bar_humi = lv_bar_create(cont_humi);
        lv_obj_set_name(bar_humi, "bar_humi");
        lv_obj_set_align(bar_humi, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_width(bar_humi, 74);
        lv_obj_set_height(bar_humi, 4);
        lv_bar_set_min_value(bar_humi, 0);
        lv_bar_set_max_value(bar_humi, 100);
        lv_bar_set_value(bar_humi, 60, false);
        lv_obj_add_style(bar_humi, &bar_track, LV_PART_MAIN);
        lv_obj_add_style(bar_humi, &bar_ind, LV_PART_INDICATOR);

        lv_obj_t * io_card = lv_obj_create(lv_obj_0);
        lv_obj_set_flag(io_card, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(io_card, "io_card");
        lv_obj_set_x(io_card, 48);
        lv_obj_set_y(io_card, 378);
        lv_obj_set_width(io_card, 452);
        lv_obj_set_height(io_card, 214);
        lv_obj_add_style(io_card, &card, 0);
        lv_obj_t * io_divider = lv_obj_create(io_card);
        lv_obj_set_flag(io_divider, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(io_divider, "io_divider");
        lv_obj_set_x(io_divider, 230);
        lv_obj_set_y(io_divider, 20);
        lv_obj_set_width(io_divider, 1);
        lv_obj_set_height(io_divider, 174);
        lv_obj_add_style(io_divider, &divider, 0);

        lv_obj_t * di_title = lv_label_create(io_card);
        lv_obj_set_name(di_title, "di_title");
        lv_obj_set_x(di_title, 16);
        lv_obj_set_y(di_title, 20);
        lv_label_set_text(di_title, "数字量输入 DI(4)");
        lv_obj_set_style_text_font(di_title, font_h4, 0);
        lv_obj_set_style_text_color(di_title, lv_color_hex(0x17191c), 0);

        lv_obj_t * di_caption = lv_label_create(io_card);
        lv_obj_set_name(di_caption, "di_caption");
        lv_obj_set_x(di_caption, 46);
        lv_obj_set_y(di_caption, 58);
        lv_label_set_text(di_caption, "DI1");
        lv_obj_set_style_text_font(di_caption, font_small, 0);
        lv_obj_set_style_text_color(di_caption, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * di1 = lv_obj_create(io_card);
        lv_obj_set_flag(di1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(di1, "di1");
        lv_obj_set_x(di1, 16);
        lv_obj_set_y(di1, 84);
        lv_obj_set_width(di1, 94);
        lv_obj_set_height(di1, 34);
        lv_obj_add_style(di1, &btn_on, 0);
        lv_obj_t * lv_label_0 = lv_label_create(di1);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_0, "ON");
        lv_obj_set_style_text_font(lv_label_0, font_body, 0);
        lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0xffffff), 0);

        lv_obj_t * di2 = lv_obj_create(io_card);
        lv_obj_set_flag(di2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(di2, "di2");
        lv_obj_set_x(di2, 120);
        lv_obj_set_y(di2, 84);
        lv_obj_set_width(di2, 94);
        lv_obj_set_height(di2, 34);
        lv_obj_add_style(di2, &btn_off, 0);
        lv_obj_t * lv_label_1 = lv_label_create(di2);
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_1, "ON");
        lv_obj_set_style_text_font(lv_label_1, font_body, 0);
        lv_obj_set_style_text_color(lv_label_1, lv_color_hex(0x6b7075), 0);

        lv_obj_t * di3 = lv_obj_create(io_card);
        lv_obj_set_flag(di3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(di3, "di3");
        lv_obj_set_x(di3, 16);
        lv_obj_set_y(di3, 126);
        lv_obj_set_width(di3, 94);
        lv_obj_set_height(di3, 34);
        lv_obj_add_style(di3, &btn_off, 0);
        lv_obj_t * lv_label_2 = lv_label_create(di3);
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_2, "ON");
        lv_obj_set_style_text_font(lv_label_2, font_body, 0);
        lv_obj_set_style_text_color(lv_label_2, lv_color_hex(0x6b7075), 0);

        lv_obj_t * di4 = lv_obj_create(io_card);
        lv_obj_set_flag(di4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(di4, "di4");
        lv_obj_set_x(di4, 120);
        lv_obj_set_y(di4, 126);
        lv_obj_set_width(di4, 94);
        lv_obj_set_height(di4, 34);
        lv_obj_add_style(di4, &btn_off, 0);
        lv_obj_t * lv_label_3 = lv_label_create(di4);
        lv_obj_set_align(lv_label_3, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_3, "OFF");
        lv_obj_set_style_text_font(lv_label_3, font_body, 0);
        lv_obj_set_style_text_color(lv_label_3, lv_color_hex(0x6b7075), 0);

        lv_obj_t * do_title = lv_label_create(io_card);
        lv_obj_set_name(do_title, "do_title");
        lv_obj_set_x(do_title, 246);
        lv_obj_set_y(do_title, 20);
        lv_label_set_text(do_title, "数字量输出 DO(4)");
        lv_obj_set_style_text_font(do_title, font_h4, 0);
        lv_obj_set_style_text_color(do_title, lv_color_hex(0x17191c), 0);

        lv_obj_t * do_caption = lv_label_create(io_card);
        lv_obj_set_name(do_caption, "do_caption");
        lv_obj_set_x(do_caption, 276);
        lv_obj_set_y(do_caption, 58);
        lv_label_set_text(do_caption, "DO1");
        lv_obj_set_style_text_font(do_caption, font_small, 0);
        lv_obj_set_style_text_color(do_caption, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * do1 = lv_obj_create(io_card);
        lv_obj_set_flag(do1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(do1, "do1");
        lv_obj_set_x(do1, 246);
        lv_obj_set_y(do1, 84);
        lv_obj_set_width(do1, 90);
        lv_obj_set_height(do1, 34);
        lv_obj_add_style(do1, &btn_on, 0);
        lv_obj_t * lv_label_4 = lv_label_create(do1);
        lv_obj_set_align(lv_label_4, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_4, "ON");
        lv_obj_set_style_text_font(lv_label_4, font_body, 0);
        lv_obj_set_style_text_color(lv_label_4, lv_color_hex(0xffffff), 0);

        lv_obj_t * do2 = lv_obj_create(io_card);
        lv_obj_set_flag(do2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(do2, "do2");
        lv_obj_set_x(do2, 346);
        lv_obj_set_y(do2, 84);
        lv_obj_set_width(do2, 90);
        lv_obj_set_height(do2, 34);
        lv_obj_add_style(do2, &btn_off, 0);
        lv_obj_t * lv_label_5 = lv_label_create(do2);
        lv_obj_set_align(lv_label_5, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_5, "OFF");
        lv_obj_set_style_text_font(lv_label_5, font_body, 0);
        lv_obj_set_style_text_color(lv_label_5, lv_color_hex(0x6b7075), 0);

        lv_obj_t * do3 = lv_obj_create(io_card);
        lv_obj_set_flag(do3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(do3, "do3");
        lv_obj_set_x(do3, 246);
        lv_obj_set_y(do3, 126);
        lv_obj_set_width(do3, 90);
        lv_obj_set_height(do3, 34);
        lv_obj_add_style(do3, &btn_off, 0);
        lv_obj_t * lv_label_6 = lv_label_create(do3);
        lv_obj_set_align(lv_label_6, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_6, "ON");
        lv_obj_set_style_text_font(lv_label_6, font_body, 0);
        lv_obj_set_style_text_color(lv_label_6, lv_color_hex(0x6b7075), 0);

        lv_obj_t * do4 = lv_obj_create(io_card);
        lv_obj_set_flag(do4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(do4, "do4");
        lv_obj_set_x(do4, 346);
        lv_obj_set_y(do4, 126);
        lv_obj_set_width(do4, 90);
        lv_obj_set_height(do4, 34);
        lv_obj_add_style(do4, &btn_off, 0);
        lv_obj_t * lv_label_7 = lv_label_create(do4);
        lv_obj_set_align(lv_label_7, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_7, "OFF");
        lv_obj_set_style_text_font(lv_label_7, font_body, 0);
        lv_obj_set_style_text_color(lv_label_7, lv_color_hex(0x6b7075), 0);

        lv_obj_t * alarm_card = lv_obj_create(lv_obj_0);
        lv_obj_set_flag(alarm_card, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(alarm_card, "alarm_card");
        lv_obj_set_x(alarm_card, 520);
        lv_obj_set_y(alarm_card, 378);
        lv_obj_set_width(alarm_card, 512);
        lv_obj_set_height(alarm_card, 214);
        lv_obj_add_style(alarm_card, &card, 0);
        lv_obj_t * alarm_title = lv_label_create(alarm_card);
        lv_obj_set_name(alarm_title, "alarm_title");
        lv_obj_set_x(alarm_title, 20);
        lv_obj_set_y(alarm_title, 20);
        lv_label_set_text(alarm_title, "设备报警记录");
        lv_obj_set_style_text_font(alarm_title, font_h4, 0);
        lv_obj_set_style_text_color(alarm_title, lv_color_hex(0x17191c), 0);

        lv_obj_t * alarm_table = lv_obj_create(alarm_card);
        lv_obj_set_flag(alarm_table, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(alarm_table, "alarm_table");
        lv_obj_set_x(alarm_table, 20);
        lv_obj_set_y(alarm_table, 52);
        lv_obj_set_width(alarm_table, 472);
        lv_obj_set_height(alarm_table, 160);
        lv_obj_add_style(alarm_table, &plain, 0);
        lv_obj_t * th_time = lv_label_create(alarm_table);
        lv_obj_set_name(th_time, "th_time");
        lv_obj_set_x(th_time, 8);
        lv_obj_set_y(th_time, 4);
        lv_label_set_text(th_time, "时间");
        lv_obj_set_style_text_font(th_time, font_small, 0);
        lv_obj_set_style_text_color(th_time, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * th_dev = lv_label_create(alarm_table);
        lv_obj_set_name(th_dev, "th_dev");
        lv_obj_set_x(th_dev, 84);
        lv_obj_set_y(th_dev, 4);
        lv_label_set_text(th_dev, "设备");
        lv_obj_set_style_text_font(th_dev, font_small, 0);
        lv_obj_set_style_text_color(th_dev, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * th_msg = lv_label_create(alarm_table);
        lv_obj_set_name(th_msg, "th_msg");
        lv_obj_set_x(th_msg, 184);
        lv_obj_set_y(th_msg, 4);
        lv_label_set_text(th_msg, "报警内容");
        lv_obj_set_style_text_font(th_msg, font_small, 0);
        lv_obj_set_style_text_color(th_msg, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * th_level = lv_label_create(alarm_table);
        lv_obj_set_name(th_level, "th_level");
        lv_obj_set_align(th_level, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(th_level, -24);
        lv_obj_set_y(th_level, 4);
        lv_label_set_text(th_level, "等级");
        lv_obj_set_style_text_font(th_level, font_small, 0);
        lv_obj_set_style_text_color(th_level, lv_color_hex(0x9aa0a6), 0);

        lv_obj_t * hline_1 = lv_obj_create(alarm_table);
        lv_obj_set_flag(hline_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(hline_1, "hline_1");
        lv_obj_set_x(hline_1, 8);
        lv_obj_set_y(hline_1, 28);
        lv_obj_set_width(hline_1, 456);
        lv_obj_set_height(hline_1, 1);
        lv_obj_add_style(hline_1, &hline, 0);

        lv_obj_t * r1_time = lv_label_create(alarm_table);
        lv_obj_set_name(r1_time, "r1_time");
        lv_obj_set_x(r1_time, 8);
        lv_obj_set_y(r1_time, 45);
        lv_label_set_text(r1_time, "10:02");
        lv_obj_set_style_text_font(r1_time, font_body, 0);
        lv_obj_set_style_text_color(r1_time, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r1_dev = lv_label_create(alarm_table);
        lv_obj_set_name(r1_dev, "r1_dev");
        lv_obj_set_x(r1_dev, 84);
        lv_obj_set_y(r1_dev, 45);
        lv_label_set_text(r1_dev, "3#传送带");
        lv_obj_set_style_text_font(r1_dev, font_body, 0);
        lv_obj_set_style_text_color(r1_dev, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r1_msg = lv_label_create(alarm_table);
        lv_obj_set_name(r1_msg, "r1_msg");
        lv_obj_set_x(r1_msg, 184);
        lv_obj_set_y(r1_msg, 45);
        lv_label_set_text(r1_msg, "过载报警");
        lv_obj_set_style_text_font(r1_msg, font_body, 0);
        lv_obj_set_style_text_color(r1_msg, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r1_badge = lv_obj_create(alarm_table);
        lv_obj_set_flag(r1_badge, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(r1_badge, "r1_badge");
        lv_obj_set_x(r1_badge, 394);
        lv_obj_set_y(r1_badge, 42);
        lv_obj_set_width(r1_badge, 62);
        lv_obj_set_height(r1_badge, 24);
        lv_obj_set_style_bg_color(r1_badge, lv_color_hex(0xe23a2e), 0);
        lv_obj_set_style_bg_opa(r1_badge, (255 * 100 / 100), 0);
        lv_obj_add_style(r1_badge, &badge, 0);
        lv_obj_t * lv_label_8 = lv_label_create(r1_badge);
        lv_obj_set_align(lv_label_8, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_8, "严重");
        lv_obj_set_style_text_font(lv_label_8, font_small, 0);
        lv_obj_set_style_text_color(lv_label_8, lv_color_hex(0xffffff), 0);

        lv_obj_t * hline_2 = lv_obj_create(alarm_table);
        lv_obj_set_flag(hline_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(hline_2, "hline_2");
        lv_obj_set_x(hline_2, 8);
        lv_obj_set_y(hline_2, 74);
        lv_obj_set_width(hline_2, 456);
        lv_obj_set_height(hline_2, 1);
        lv_obj_add_style(hline_2, &hline, 0);

        lv_obj_t * r2_time = lv_label_create(alarm_table);
        lv_obj_set_name(r2_time, "r2_time");
        lv_obj_set_x(r2_time, 8);
        lv_obj_set_y(r2_time, 85);
        lv_label_set_text(r2_time, "09:45");
        lv_obj_set_style_text_font(r2_time, font_body, 0);
        lv_obj_set_style_text_color(r2_time, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r2_dev = lv_label_create(alarm_table);
        lv_obj_set_name(r2_dev, "r2_dev");
        lv_obj_set_x(r2_dev, 84);
        lv_obj_set_y(r2_dev, 85);
        lv_label_set_text(r2_dev, "冷库");
        lv_obj_set_style_text_font(r2_dev, font_body, 0);
        lv_obj_set_style_text_color(r2_dev, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r2_msg = lv_label_create(alarm_table);
        lv_obj_set_name(r2_msg, "r2_msg");
        lv_obj_set_x(r2_msg, 184);
        lv_obj_set_y(r2_msg, 85);
        lv_label_set_text(r2_msg, "温度偏高");
        lv_obj_set_style_text_font(r2_msg, font_body, 0);
        lv_obj_set_style_text_color(r2_msg, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r2_badge = lv_obj_create(alarm_table);
        lv_obj_set_flag(r2_badge, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(r2_badge, "r2_badge");
        lv_obj_set_x(r2_badge, 394);
        lv_obj_set_y(r2_badge, 82);
        lv_obj_set_width(r2_badge, 62);
        lv_obj_set_height(r2_badge, 24);
        lv_obj_set_style_bg_color(r2_badge, lv_color_hex(0xf2a33c), 0);
        lv_obj_set_style_bg_opa(r2_badge, (255 * 100 / 100), 0);
        lv_obj_add_style(r2_badge, &badge, 0);
        lv_obj_t * lv_label_9 = lv_label_create(r2_badge);
        lv_obj_set_align(lv_label_9, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_9, "警告");
        lv_obj_set_style_text_font(lv_label_9, font_small, 0);
        lv_obj_set_style_text_color(lv_label_9, lv_color_hex(0xffffff), 0);

        lv_obj_t * hline_3 = lv_obj_create(alarm_table);
        lv_obj_set_flag(hline_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(hline_3, "hline_3");
        lv_obj_set_x(hline_3, 8);
        lv_obj_set_y(hline_3, 114);
        lv_obj_set_width(hline_3, 456);
        lv_obj_set_height(hline_3, 1);
        lv_obj_add_style(hline_3, &hline, 0);

        lv_obj_t * r3_time = lv_label_create(alarm_table);
        lv_obj_set_name(r3_time, "r3_time");
        lv_obj_set_x(r3_time, 8);
        lv_obj_set_y(r3_time, 125);
        lv_label_set_text(r3_time, "09:21");
        lv_obj_set_style_text_font(r3_time, font_body, 0);
        lv_obj_set_style_text_color(r3_time, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r3_dev = lv_label_create(alarm_table);
        lv_obj_set_name(r3_dev, "r3_dev");
        lv_obj_set_x(r3_dev, 84);
        lv_obj_set_y(r3_dev, 125);
        lv_label_set_text(r3_dev, "2#风机");
        lv_obj_set_style_text_font(r3_dev, font_body, 0);
        lv_obj_set_style_text_color(r3_dev, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r3_msg = lv_label_create(alarm_table);
        lv_obj_set_name(r3_msg, "r3_msg");
        lv_obj_set_x(r3_msg, 184);
        lv_obj_set_y(r3_msg, 125);
        lv_label_set_text(r3_msg, "振动异常");
        lv_obj_set_style_text_font(r3_msg, font_body, 0);
        lv_obj_set_style_text_color(r3_msg, lv_color_hex(0x4c5257), 0);

        lv_obj_t * r3_badge = lv_obj_create(alarm_table);
        lv_obj_set_flag(r3_badge, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_name(r3_badge, "r3_badge");
        lv_obj_set_x(r3_badge, 394);
        lv_obj_set_y(r3_badge, 122);
        lv_obj_set_width(r3_badge, 62);
        lv_obj_set_height(r3_badge, 24);
        lv_obj_set_style_bg_color(r3_badge, lv_color_hex(0xf2a33c), 0);
        lv_obj_set_style_bg_opa(r3_badge, (255 * 100 / 100), 0);
        lv_obj_add_style(r3_badge, &badge, 0);
        lv_obj_t * lv_label_10 = lv_label_create(r3_badge);
        lv_obj_set_align(lv_label_10, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_10, "警告");
        lv_obj_set_style_text_font(lv_label_10, font_small, 0);
        lv_obj_set_style_text_color(lv_label_10, lv_color_hex(0xffffff), 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

