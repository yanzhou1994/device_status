/**
 * @file device_status.c
 * @brief Entry point of the UI project "device_status".
 *
 * Generated projects keep the (re)generated code in *_gen.c and reserve this
 * file for hand written additions. It simply forwards to the generated init.
 *
 * The digital outputs (DO1..DO4) are lv_button widgets in the XML: this file
 * adds the click behaviour that switches them between ON and OFF.
 * DI1..DI4 are read only status displays and need no code.
 */

/*********************
 *      INCLUDES
 *********************/

#include "device_status.h"

#include <string.h>

/*********************
 *      DEFINES
 *********************/

#define DO_COUNT 4

#define COLOR_MARK_ON  0x16a6a1
#define COLOR_MARK_OFF 0xf0f2f5
#define COLOR_TEXT_ON  0xffffff
#define COLOR_TEXT_OFF 0x8a9096

/***********************
 *  STATIC VARIABLES
 **********************/

/* Object names as written in screens/device_status_main.xml */
static const char * do_tile_names[DO_COUNT] = {"do1", "do2", "do3", "do4"};
static const char * do_state_names[DO_COUNT] = {"do1_state", "do2_state", "do3_state", "do4_state"};

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void do_apply(lv_obj_t * mark, bool on);
static void do_tile_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void device_status_init(const char * asset_path)
{
    device_status_init_gen(asset_path);

    /* Add your own custom code here if needed */
}

void device_status_io_init(lv_obj_t * root)
{
    if(root == NULL) return;

    for(int i = 0; i < DO_COUNT; i++) {
        lv_obj_t * tile = lv_obj_find_by_name(root, do_tile_names[i]);
        if(tile == NULL) continue;

        lv_obj_t * mark = lv_obj_get_child_by_name(tile, do_state_names[i]);
        if(mark == NULL) continue;

        /* The ON/OFF text defined in the XML is the initial state */
        lv_obj_t * label = lv_obj_get_child(mark, 0);
        do_apply(mark, label && strcmp(lv_label_get_text(label), "ON") == 0);

        lv_obj_add_event_cb(tile, do_tile_event_cb, LV_EVENT_CLICKED, (void *)do_state_names[i]);
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void do_apply(lv_obj_t * mark, bool on)
{
    lv_obj_set_style_bg_color(mark, lv_color_hex(on ? COLOR_MARK_ON : COLOR_MARK_OFF), 0);

    lv_obj_t * label = lv_obj_get_child(mark, 0);
    if(label == NULL) return;
    lv_label_set_text(label, on ? "ON" : "OFF");
    lv_obj_set_style_text_color(label, lv_color_hex(on ? COLOR_TEXT_ON : COLOR_TEXT_OFF), 0);
}

static void do_tile_event_cb(lv_event_t * e)
{
    lv_obj_t * tile = lv_event_get_current_target(e);
    const char * state_name = (const char *)lv_event_get_user_data(e);
    if(state_name == NULL) return;

    lv_obj_t * mark = lv_obj_get_child_by_name(tile, state_name);
    if(mark == NULL) return;

    lv_obj_t * label = lv_obj_get_child(mark, 0);
    bool on = label && strcmp(lv_label_get_text(label), "ON") == 0;
    do_apply(mark, !on);
}
