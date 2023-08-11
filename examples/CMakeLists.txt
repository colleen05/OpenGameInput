# Project: OpenGameInput
# File: examples/CMakeLists.txt
# Description: Examples CMake build configuration.
# License: MIT
# https://github.com/colleen05/OpenGameInput

project(Examples)

file(GLOB EXAMPLES_SOURCE_FILES "*.cpp")

foreach(EXAMPLE_SOURCE_FILE ${EXAMPLES_SOURCE_FILES})
    # Get example name
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE_FILE} NAME)
    string(REPLACE ".cpp" "" EXAMPLE_NAME ${EXAMPLE_NAME})

    # Add the example as an executable
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE_FILE})

    target_link_libraries(${EXAMPLE_NAME} OpenGameInput)
endforeach()
