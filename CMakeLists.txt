cmake_minimum_required(VERSION 4.0)

# Set plugin name and other variables for project here: 
set(PLUGIN_NAME "PluginName")
set(PLUGIN_VERSION "0.1.0")
set(COMPANY_NAME "Umbrae")
set(PLUGIN_MANUFACTURER_CODE "UMBR")
set(PLUGIN_CODE "Dem0")

project(${PLUGIN_NAME})

set(CMAKE_CXX_STANDARD 23)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
# include script to download CPM.cmake
include(cmake/cpm.cmake)


CPMAddPackage(
    NAME JUCE
    GITHUB_REPOSITORY juce-framework/JUCE
    GIT_TAG 8.0.10
    version 8.0.10
    SOURCE_DIR ${LIB_DIR}/JUCE
)
CPMaddPackage(
    NAME GOOGLETEST
    GITHUB_REPOSITORY google/googletest
    # GIT_TAG 1.17.0
    VERSION 1.17.0
    SOURCE_DIR ${LIB_DIR}/googletest
    OPTIONS
        "INSTALL_GTEST OFF"
        "Gtest_force_shared_crt ON"
)
enable_testing()

# opsætning af treat warnings as errors
if (MSVC)
    add_compile_options(/Wall /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(plugin)
add_subdirectory(test)