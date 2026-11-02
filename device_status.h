/**
 * @file device_status.h
 * @brief Entry point of the UI project "device_status".
 */

#ifndef DEVICE_STATUS_H
#define DEVICE_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "device_status_gen.h"

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the UI: load the fonts declared in globals.xml.
 * Call it once before creating any screen.
 * @param asset_path  drive prefix for file based assets, e.g. "A:"
 */
void device_status_init(const char * asset_path);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*DEVICE_STATUS_H*/
