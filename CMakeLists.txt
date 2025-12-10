cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# set up project
project(scryptor
        DESCRIPTION "A tool to freely encrypt or decrypt Source engine file formats."
        VERSION 1.0.0
        HOMEPAGE_URL "https://github.com/craftablescience/scryptor")
set(PROJECT_ORGANIZATION_NAME "craftablescience" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add helpers
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/helpers")
include(CS_All)

# initial VS integration
cs_setup_vs_defaults(STARTUP_PROJECT "${PROJECT_NAME}")

# set common compile options
option(SCRYPTOR_USE_LTO "Compile ${PROJECT_NAME} with LTO/IPO" OFF)
cs_configure_defaults(SCRYPTOR_USE_LTO)

# external libraries
cs_include_directory(ext)

# scryptor
add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/src/scryptor.cpp")
cs_configure_target(${PROJECT_NAME} MANIFEST)
target_link_libraries(${PROJECT_NAME} PRIVATE sourcepp::vcryptpp)

# copy the license
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/LICENSE" "${CMAKE_BINARY_DIR}/LICENSE" COPYONLY)
