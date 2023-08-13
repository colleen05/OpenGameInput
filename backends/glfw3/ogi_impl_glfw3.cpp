// Project: OpenGameInput
// File: backends/glfw3/ogi_impl_glfw3.cpp
// Description: GLFW 3 backend for OpenGameInput.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#include "ogi_impl_glfw3.hpp"

#include <iostream>

void _key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    return;
}

ogi::system ogiGLFW::init(GLFWwindow *window) {
    ogi::print_lib_info();
    ogi::system inputSystem;

    glfwSetKeyCallback(window, &_key_callback);
    
    return inputSystem;
}