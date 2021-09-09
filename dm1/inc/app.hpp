#pragma once
#include "prereq.hpp"

class DemoApplication {
public:
    void run();

private:
    void _init_window();
    void _init_vulkan();
    void _loop();
    void _cleanup();

private:
    GLFWwindow* _wnd;
};



