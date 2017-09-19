
# Throw a fatal error if version is < 3.6.
cmake_minimum_required (VERSION 3.6 FATAL_ERROR)

# Setup name for project.
set(PROJECT_NAME random)
# Variables used to represent the version.
set (RANDOM_VERSION_MAJOR 2)
set (RANDOM_VERSION_MINOR 0)
set (RANDOM_VERSION_PATCH 0)
# Type of build.
set(CMAKE_BUILD_TYPE Release)
# Set the project source dir (just convention)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Setup the list of source file(s).
set(SOURCES
        ${SOURCE_DIR}/Random.c)
# Setup the list of header file(s).
set(HEADERS
        ${INCLUDE_DIR}/Random.h)

# Project name and programming language.
project(${PROJECT_NAME} C)

# Send the variables (version number) to source code header
configure_file (
        "Config.h.in"
        "${INCLUDE_DIR}/Config.h"
)

# Include directories.
include_directories(${INCLUDE_DIR})

# Create the static library.
add_library(RANDOM_LIB SHARED ${SOURCES})