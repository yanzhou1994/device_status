/**
 * @file device_status_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "device_status.h"

#if defined(LV_USE_XML) && LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t device_status_target = DEVICE_STATUS_COMPILE_TARGET;

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_title;
extern lv_font_t font_title_default_data;
lv_font_t * font_value;
extern lv_font_t font_value_default_data;
lv_font_t * font_h3;
extern lv_font_t font_h3_default_data;
lv_font_t * font_h4;
extern lv_font_t font_h4_default_data;
lv_font_t * font_body;
extern lv_font_t font_body_default_data;
lv_font_t * font_small;
extern lv_font_t font_small_default_data;

/*----------------
 * Images
 *----------------*/



/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void device_status_init_gen(const char * asset_path)
{

    /*----------------
     * Fonts
     *----------------*/

    /* Targets: default */

    #if DEVICE_STATUS_CHECK_COMPILE_TARGET(DEVICE_STATUS_TARGET_DEFAULT)
    if (device_status_check_target(DEVICE_STATUS_TARGET_DEFAULT)) {
        if (!font_title) {
            /* font_title */
            /* get font 'font_title' from a C array */
            font_title = &font_title_default_data;

        }
        if (!font_value) {
            /* font_value */
            /* get font 'font_value' from a C array */
            font_value = &font_value_default_data;

        }
        if (!font_h3) {
            /* font_h3 */
            /* get font 'font_h3' from a C array */
            font_h3 = &font_h3_default_data;

        }
        if (!font_h4) {
            /* font_h4 */
            /* get font 'font_h4' from a C array */
            font_h4 = &font_h4_default_data;

        }
        if (!font_body) {
            /* font_body */
            /* get font 'font_body' from a C array */
            font_body = &font_body_default_data;

        }
        if (!font_small) {
            /* font_small */
            /* get font 'font_small' from a C array */
            font_small = &font_small_default_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/



    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    /*----------------
     * Translations
     *----------------*/

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_title, "font_title");
    check_font(&font_value, "font_value");
    check_font(&font_h3, "font_h3");
    check_font(&font_h4, "font_h4");
    check_font(&font_body, "font_body");
    check_font(&font_small, "font_small");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_title", font_title);
    lv_xml_register_font(NULL, "font_value", font_value);
    lv_xml_register_font(NULL, "font_h3", font_h3);
    lv_xml_register_font(NULL, "font_h4", font_h4);
    lv_xml_register_font(NULL, "font_body", font_body);
    lv_xml_register_font(NULL, "font_small", font_small);

    /* Register subjects */

    /* Register callbacks */

    /* Register easing callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if !defined(LV_USE_XML) || LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void device_status_set_target(uint32_t target)
{
    device_status_target = target;
}

uint32_t device_status_get_target(void)
{
    return device_status_target;
}

bool device_status_check_target(uint32_t target)
{
    return (device_status_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}