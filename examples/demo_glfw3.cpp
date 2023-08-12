// Project: OpenGameInput
// File: examples/demo_glfw3.cpp
// Description: OpenGameInput demo for GLFW backend.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#include "ogi_impl_glfw3.hpp"

int main() {
    if(!glfwInit()) return -1;

    ogi::init();

    GLFWwindow *window = glfwCreateWindow(640, 480, "OpenGameInput", NULL, NULL);

    if(!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}