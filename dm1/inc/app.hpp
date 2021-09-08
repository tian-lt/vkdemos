#pragma once
#include <memory>
#include "GLFW/glfw3.h"
#include "vkinstance.hpp"

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
    std::unique_ptr<VKInstance> _vkinst;
};



