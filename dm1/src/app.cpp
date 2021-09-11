#include <cstdint>
#include <iostream>
#include <thread>
#include "app.hpp"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr const char* WINDOW_TITLE = "DM1 - Demo Application";
constexpr const char* APP_NAME = "DM1 - Demo Application";
constexpr const char* ENGINE_NAME = "NoEngine";

void DemoApplication::run() {
    _init();
    _loop();
    _cleanup();
}

void DemoApplication::_init() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    _wnd = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, nullptr, nullptr);
    _vkctx = std::make_unique<VKContext>();
    _vkctx->initialize(_wnd, APP_NAME, ENGINE_NAME, TEST_RESOURCES_DIR);
}

void DemoApplication::_loop() {
    while (!glfwWindowShouldClose(_wnd)) {
        glfwPollEvents();
        _render();
        _vkctx->wait_for_device_idle();
    }
}

void DemoApplication::_cleanup() {
    _vkctx.reset();
    glfwDestroyWindow(_wnd);
    glfwTerminate();
}

void DemoApplication::_render() {
    using namespace std::chrono_literals;
    static int frame = 0;
    std::cout << "frame number: " << frame++ << std::endl;
    _vkctx->draw_frame();
    std::this_thread::sleep_for(16ms);
}



