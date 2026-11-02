# =============================================================================
# user_config.cmake - Add your custom source files here
# =============================================================================
#
# This file is included by the generated CMakeLists.txt and allows you to
# add extra source files to the project without modifying generated files
# (which may be overwritten).
#
#   list(APPEND LV_EDITOR_PROJECT_SOURCES
#       ${CMAKE_CURRENT_LIST_DIR}/src/my_widget.c
#   )
#
# =============================================================================

list(APPEND LV_EDITOR_PROJECT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/device_status.c
)

# =============================================================================
# MSVC: 强制按 UTF-8 解析源文件
# =============================================================================
# 源文件不含 BOM，MSVC 默认按系统 ANSI(GBK) 解析，
# 遇到中文字面量会吞掉右引号，报 C2001 字符串字面量中的换行符。
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")

# =============================================================================
# MSVC: 忽略 GCC 专有的 __attribute__((...))
# =============================================================================
# 字体/图片数据文件里可能带 __attribute__((section("...")))，
# MSVC 不认识，会报 C2059/C2061。该属性只影响链接段布局，
# Windows 仿真下无意义，置空即可。
if(MSVC)
    add_compile_options("/FI\"${CMAKE_CURRENT_LIST_DIR}/msvc_compat.h\"")
endif()
