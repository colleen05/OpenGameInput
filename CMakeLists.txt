# Project: OpenGameInput
# File: CMakeLists.txt
# Description: OpenGameInput CMake build configuration.
# License: MIT
# https://github.com/colleen05/OpenGameInput

cmake_minimum_required(VERSION 3.16)
project(
    OpenGameInput
    VERSION 0.0.1
    DESCRIPTION "Game-oriented input abstraction for C++17."
    HOMEPAGE_URL "https://github.com/colleen05/OpenGameInput"
)
set(CMAKE_CXX_STANDARD 17)

# if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
#     set(CMAKE_CXX_FLAGS "-gdwarf-4")
# endif()

# set(BUILD_SHARED_LIBS OFF)
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# OpenGameInput
set(OGI_SOURCE_DIR "src")
set(OGI_INCLUDE_DIR "include")

file(GLOB_RECURSE OGI_SOURCE_FILES "${OGI_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE OGI_INCLUDE_FILES "${OGI_INCLUDE_DIR}/*.hpp")

add_library(OpenGameInput STATIC ${OGI_SOURCE_FILES})

target_include_directories(
    OpenGameInput
    PUBLIC ${OGI_INCLUDE_DIR}
)

# Examples
if(${BUILD_EXAMPLES})
    add_subdirectory("examples")
endif()
