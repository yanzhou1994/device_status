/**
 * @file main.c
 *
 * PC simulator entry point for the UI exported from LVGL Pro: opens a window,
 * initializes the exported UI library and starts the LVGL loop.
 */

/* Built only by sim/CMakeLists.txt; lets a glob-based embedded build skip it. */
#ifdef LVGL_PRO_SIMULATOR_BUILD

#include "lvgl.h"
#include "hal.h"
#include "device_status.h"
#include "screens/device_status_main_gen.h"

int main(void)
{
    lv_init();

    /* Never wrap the following init in lv_lock()/lv_unlock().
     *
     * The Win32 driver creates the window on its own thread and that thread's
     * window procedure calls lv_lock() itself. CreateWindowExW dispatches
     * WM_CREATE synchronously, so holding the lock here deadlocks. */

    lv_display_t * disp = hal_init(UI_WIDTH, UI_HEIGHT);

    device_status_init("A:");   /* "A:" = file-system drive for file-based assets */

    /* Wait until the driver has allocated its draw buffer. */
    for(int i = 0; i < 100 && lv_display_get_buf_active(disp) == NULL; i++) {
        lv_timer_handler();
        lv_sleep_ms(LV_DEF_REFR_PERIOD);
    }

    /* Load the only screen of the project. */
    lv_screen_load(device_status_main_create());

    while(1) {
        uint32_t idle_ms = lv_timer_handler();
        if(idle_ms == LV_NO_TIMER_READY) idle_ms = LV_DEF_REFR_PERIOD;
        lv_sleep_ms(idle_ms);
    }

    return 0;
}

#endif /*LVGL_PRO_SIMULATOR_BUILD*/
