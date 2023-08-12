# Project: OpenGameInput
# File: examples/CMakeLists.txt
# Description: Examples CMake build configuration.
# License: MIT
# https://github.com/colleen05/OpenGameInput

project(Examples)

if(NOT DEFINED OGI_EXAMPLES_BACKEND)
    message(FATAL_ERROR "OpenGameInput examples cannot be built: Please set OGI_EXAMPLES_BACKEND.")
else()
    if(OGI_EXAMPLES_BACKEND STREQUAL "GLFW")
        set(BACKEND_LIB "glfw")
        set(BACKEND_DIR "${CMAKE_SOURCE_DIR}/backends/glfw3")
        set(BACKEND_SOURCE "${BACKEND_DIR}/ogi_impl_glfw3.cpp")
        set(BACKEND_HEADER "${BACKEND_DIR}/ogi_impl_glfw3.hpp")
        add_subdirectory("external/glfw3")
    else()
        message(FATAL_ERROR "OpenGameInput examples cannot be built: Unknown backend \"${OGI_EXAMPLES_BACKEND}\". Examples cannot use custom backends.")
    endif()
endif()

file(GLOB EXAMPLES_SOURCE_FILES "*.cpp")

foreach(EXAMPLE_SOURCE_FILE ${EXAMPLES_SOURCE_FILES})
    # Get example name
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE_FILE} NAME)
    string(REPLACE ".cpp" "" EXAMPLE_NAME ${EXAMPLE_NAME})

    # Add the example as an executable
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE_FILE} ${BACKEND_SOURCE})

    target_include_directories(
        ${EXAMPLE_NAME}
        PUBLIC ${BACKEND_DIR}
    )

    target_link_libraries(
        ${EXAMPLE_NAME}
        OpenGameInput
        ${BACKEND_LIB}
    )
endforeach()
