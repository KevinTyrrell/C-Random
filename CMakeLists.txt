
# Throw a fatal error if version is < 3.6.
cmake_minimum_required (VERSION 3.6 FATAL_ERROR)

# Variables used to represent the version.
set (RANDOM_PROJECT_NAME C-Random)
set (RANDOM_VERSION_MAJOR 3)
set (RANDOM_VERSION_MINOR 0)
set (RANDOM_VERSION_PATCH 0)
set (RANDOM_VERSION_STR "${RANDOM_VERSION_MAJOR}.${RANDOM_VERSION_MINOR}.${RANDOM_VERSION_PATCH}")

# Build type.
set (CMAKE_BUILD_TYPE Release)

# Set the project source dir (just convention)
set (RANDOM_SOURCE_DIR src)
set (RANDOM_INCLUDE_DIR include)

# Source files for compiling.
set (RANDOM_SOURCES
        ${RANDOM_SOURCE_DIR}/Random.c)

# Send the variables (version number) to source code header
set (RANDOM_CONFIG_FILE Config.h)
configure_file (
        "${RANDOM_CONFIG_FILE}.in"
        "${RANDOM_INCLUDE_DIR}/${RANDOM_CONFIG_FILE}")

# Project setup.
project(${RANDOM_PROJECT_NAME} C)
# Add the library to be linked.
add_library(${RANDOM_PROJECT_NAME} STATIC ${RANDOM_SOURCES})

