# ===========================================================================
#  PC simulator for the UI exported from LVGL Pro ("device_status").
#
#  Configure this folder (sim/) as the CMake source directory to build and run
#  the UI on a desktop:
#
#      cmake -S sim -B build -G "Visual Studio 18 2026"
#      cmake --build build --config Debug
#      build/bin/lvgl_simulator.exe
#
#  LVGL is taken from a local checkout when one is available (see
#  -DLVGL_LOCAL_DIR=...), otherwise it is fetched from GitHub.
# ===========================================================================

cmake_minimum_required(VERSION 3.16)
project(lvgl_simulator C)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# LVGL version used when LVGL has to be downloaded.
set(LVGL_VERSION "v9.5.0" CACHE STRING "LVGL version (git tag or branch)")

# Folder with the UI exported from LVGL Pro (the parent of this sim/ folder).
set(UI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "Folder with the exported UI")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

# ---------------------------------------------------------------------------
#  Source encoding
#
#  All UI sources (XML, generated *.c, fonts) are UTF-8 without BOM. MSVC
#  defaults to the system code page (GBK/936) and would silently mis-decode
#  Chinese string literals -> C4819 / mojibake / dropped glyphs. Force UTF-8
#  for every target created from here on (lib-ui, lvgl, the executable).
# ---------------------------------------------------------------------------
if(MSVC)
  add_compile_options(/utf-8)
endif()

# ---------------------------------------------------------------------------
#  LVGL source tree
#
#  Prefer an already existing checkout (fast, works offline). Point
#  -DLVGL_LOCAL_DIR at any LVGL v9 source tree, e.g.
#      -DLVGL_LOCAL_DIR=D:/LVGL_project/examples/build/_deps/lvgl-src
# ---------------------------------------------------------------------------
set(_lvgl_guess "")
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../../examples/build/_deps/lvgl-src/lvgl.h")
  set(_lvgl_guess "${CMAKE_CURRENT_SOURCE_DIR}/../../examples/build/_deps/lvgl-src")
endif()
set(LVGL_LOCAL_DIR "${_lvgl_guess}" CACHE PATH "Existing LVGL source tree (skips the download)")

if(LVGL_LOCAL_DIR AND EXISTS "${LVGL_LOCAL_DIR}/lvgl.h")
  get_filename_component(lvgl_SOURCE_DIR "${LVGL_LOCAL_DIR}" ABSOLUTE)
  set(lvgl_BINARY_DIR "${CMAKE_BINARY_DIR}/lvgl")
  message(STATUS "Using local LVGL: ${lvgl_SOURCE_DIR}")
else()
  include(FetchContent)
  FetchContent_Declare(
    lvgl
    GIT_REPOSITORY https://github.com/lvgl/lvgl.git
    GIT_TAG ${LVGL_VERSION}
    GIT_SHALLOW TRUE)

  FetchContent_GetProperties(lvgl)
  if(NOT lvgl_POPULATED)
    message(STATUS "Fetching LVGL ${LVGL_VERSION} ...")
    FetchContent_Populate(lvgl)
  endif()
endif()

# ---------------------------------------------------------------------------
#  Generate lv_conf.h from the platform's defaults
# ---------------------------------------------------------------------------
find_package(Python3 REQUIRED COMPONENTS Interpreter)

if(WIN32)
  set(LV_CONF_DEFAULTS "${CMAKE_CURRENT_SOURCE_DIR}/lv_conf_windows.defaults")
else()
  set(LV_CONF_DEFAULTS "${CMAKE_CURRENT_SOURCE_DIR}/lv_conf_sdl.defaults")
endif()

set(LV_CONF_PATH "${CMAKE_BINARY_DIR}/lv_conf.h")
set(LV_CONF_TMP "${CMAKE_BINARY_DIR}/lv_conf.h.in")
execute_process(
  COMMAND ${Python3_EXECUTABLE}
          "${lvgl_SOURCE_DIR}/scripts/generate_lv_conf.py"
          --template "${lvgl_SOURCE_DIR}/lv_conf_template.h"
          --defaults "${LV_CONF_DEFAULTS}"
          --config   "${LV_CONF_TMP}"
  RESULT_VARIABLE _conf_result
  OUTPUT_VARIABLE _conf_output
  ERROR_VARIABLE  _conf_output)
if(NOT _conf_result EQUAL 0)
  message(FATAL_ERROR "Failed to generate lv_conf.h:\n${_conf_output}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${LV_CONF_TMP}" "${LV_CONF_PATH}")
message(STATUS "Generated ${LV_CONF_PATH} from ${LV_CONF_DEFAULTS}")

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
             "${LV_CONF_DEFAULTS}")

set(LV_BUILD_CONF_PATH "${LV_CONF_PATH}" CACHE PATH "" FORCE)

# ---------------------------------------------------------------------------
#  Add LVGL (minimal: skip bundled demos/examples/ThorVG)
# ---------------------------------------------------------------------------
set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_USE_THORVG_INTERNAL OFF CACHE BOOL "" FORCE)

add_subdirectory(${lvgl_SOURCE_DIR} ${lvgl_BINARY_DIR})

# ---------------------------------------------------------------------------
#  Display / input backend
# ---------------------------------------------------------------------------
set(BACKEND_LIBS "")
if(WIN32)
  list(APPEND BACKEND_LIBS gdi32 user32)
else()
  find_package(SDL2 REQUIRED)
  target_include_directories(lvgl SYSTEM PUBLIC ${SDL2_INCLUDE_DIRS})
  list(APPEND BACKEND_LIBS ${SDL2_LIBRARIES})
endif()

# ---------------------------------------------------------------------------
#  UI exported from LVGL Pro
# ---------------------------------------------------------------------------
add_subdirectory(${UI_DIR} ${CMAKE_BINARY_DIR}/ui)

target_compile_definitions(lib-ui PUBLIC LV_LVGL_H_INCLUDE_SIMPLE)

# Derive the UI entry point and window size from project.xml.
file(READ "${UI_DIR}/project.xml" _project_xml)
string(REGEX MATCH "<project[^>]*name=\"([^\"]+)\"" _ "${_project_xml}")
set(UI_NAME "${CMAKE_MATCH_1}")
if(NOT UI_NAME)
  message(FATAL_ERROR "Could not read the project name from ${UI_DIR}/project.xml")
endif()
string(REGEX MATCH "<display[^>]*width=\"([0-9]+)\"[^>]*height=\"([0-9]+)\"" _ "${_project_xml}")
set(UI_WIDTH "${CMAKE_MATCH_1}")
set(UI_HEIGHT "${CMAKE_MATCH_2}")
if(NOT UI_WIDTH OR NOT UI_HEIGHT)
  set(UI_WIDTH 800)
  set(UI_HEIGHT 480)
endif()

# ---------------------------------------------------------------------------
#  Application
# ---------------------------------------------------------------------------
add_executable(${PROJECT_NAME} main.c hal.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE lib-ui lvgl ${BACKEND_LIBS})

# Flatten the Visual Studio output dir so the exe always lands in build/bin/.
foreach(_cfg ${CMAKE_CONFIGURATION_TYPES})
  string(TOUPPER "${_cfg}" _CFG)
  set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_${_CFG} "${CMAKE_BINARY_DIR}/bin")
endforeach()

# Guard the sim/ files (so a glob-based embedded build skips them) and expose
# the size of the display declared in project.xml.
target_compile_definitions(${PROJECT_NAME} PRIVATE
  LVGL_PRO_SIMULATOR_BUILD
  UI_NAME="${UI_NAME}"
  UI_WIDTH=${UI_WIDTH}
  UI_HEIGHT=${UI_HEIGHT})

if(NOT WIN32)
  target_link_libraries(${PROJECT_NAME} PRIVATE m pthread)
endif()

# Build and run from the UI folder so the "A:" asset path resolves to it.
add_custom_target(run
  COMMAND $<TARGET_FILE:${PROJECT_NAME}>
  WORKING_DIRECTORY ${UI_DIR}
  DEPENDS ${PROJECT_NAME})
