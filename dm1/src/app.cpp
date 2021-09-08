#include "app.hpp"
#include <cstdint>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr const char* WINDOW_TITLE = "DM1 - Demo Application";
constexpr const char* APP_NAME = "DM1 - Demo Application";

void DemoApplication::run() {
    _init_window();
    _loop();
    _cleanup();
}

void DemoApplication::_init_window() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    _wnd = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, nullptr, nullptr);
}

void DemoApplication::_init_vulkan() {
    _vkinst = std::make_unique<VKInstance>(APP_NAME);
}

void DemoApplication::_loop() {
    while (!glfwWindowShouldClose(_wnd)) {
        glfwPollEvents();
    }
}

void DemoApplication::_cleanup() {
    glfwDestroyWindow(_wnd);
    glfwTerminate();
}



