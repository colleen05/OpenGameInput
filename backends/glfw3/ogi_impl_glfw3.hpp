// Project: OpenGameInput
// File: backends/glfw3/ogi_impl_glfw3.hpp
// Description: GLFW 3 backend for OpenGameInput.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#ifndef OGI_BACKEND_GLFW3_HPP
#define OGI_BACKEND_GLFW3_HPP

#ifndef OGI_BACKEND
    #define OGI_BACKEND "GLFW3"
#else
    #error "Attempted to use multiple backends with OpenGameInput! You can only use one per build."
#endif

#include "GLFW/glfw3.h"
#include "oginput/ogi.hpp"
#include "oginput/system.hpp"

namespace ogiGLFW {
    static ogi::system *system;

    ogi::system *init(GLFWwindow *window);
    void shutdown();
}

#endif