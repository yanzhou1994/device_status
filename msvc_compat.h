/**
 * @file msvc_compat.h
 * MSVC 兼容垫片（由 user_config.cmake 以 /FI 方式强制包含）
 *
 * 用途：图片 / 字体数据文件里带 GCC 专有属性
 *     uint8_t data[] __attribute__((section("the_ospi_section"))) = { ... };
 * MSVC 不认 __attribute__，会报 C2059 / C2061。
 * 该属性只影响链接段布局（把数据放到 OSPI Flash 段），
 * 在 Windows 仿真环境下无意义，置空即可。
 */
#ifndef MSVC_COMPAT_H
#define MSVC_COMPAT_H

#if defined(_MSC_VER) && !defined(__attribute__)
#define __attribute__(x)
#endif

#endif /* MSVC_COMPAT_H */
