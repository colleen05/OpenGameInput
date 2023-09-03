// Project: OpenGameInput
// File: examples/demo_glfw3.cpp
// Description: OpenGameInput demo for GLFW backend.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#include "ogi_impl_glfw3.hpp"

#include <iostream>

int entcount = 0;

class entity {
    private:
        int num = 0;

    public:
        std::shared_ptr<ogi::listener> listener;


        void on_foo(float x) {
            std::cout << "[ent #" << num << "] foo: " << x << std::endl;
        }

        entity(ogi::system *sys) {
            num = entcount;
            entcount++;
            
            if(sys) {
                listener = std::make_shared<ogi::listener>();
                listener->set_callback("foo", [this](float x){on_foo(x);});
                sys->push_listener(listener);
            }

            std::cout << "Created entity " << num << "." << std::endl;
        }

        entity() : entity(nullptr) { }

        ~entity() {
            std::cout << "Destroyed entity " << num << "." << std::endl;
        }
};

int main() {
    if(!glfwInit()) return -1;

    GLFWwindow *window = glfwCreateWindow(640, 480, "OpenGameInput", NULL, NULL);
    if(!window) { glfwTerminate(); return -1; }

    ogi::system *ogi = ogiGLFW::init(window);

    std::vector<std::shared_ptr<entity>> ents;

    glfwMakeContextCurrent(window);

    bool ins_pressed = false;
    bool del_pressed = false;
    bool f_pressed = false;

    while(!glfwWindowShouldClose(window)) {
        ogi->update();

        if(!ins_pressed && (glfwGetKey(window, GLFW_KEY_INSERT) == GLFW_PRESS)) {
            ins_pressed = true;
            ents.emplace_back(new entity(ogi));
        }else if(glfwGetKey(window, GLFW_KEY_INSERT) != GLFW_PRESS) {
            ins_pressed = false;
        }

        if(!del_pressed && (glfwGetKey(window, GLFW_KEY_DELETE) == GLFW_PRESS)) {
            del_pressed = true;
            ents.clear();
        }else if(glfwGetKey(window, GLFW_KEY_DELETE) != GLFW_PRESS) {
            del_pressed = false;
        }

        if(!f_pressed && (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)) {
            f_pressed = true;

            if(ents.empty()) {
                std::cout << "No ents to invoke action 'foo'." << std::endl;
            } else {
                for(auto &e : ents) {
                    e->listener->invoke("foo", 123.456f);
                }
            }
        }else if(glfwGetKey(window, GLFW_KEY_F) != GLFW_PRESS) {
            f_pressed = false;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ents.clear();

    glfwTerminate();

    ogiGLFW::shutdown();

    return 0;
}