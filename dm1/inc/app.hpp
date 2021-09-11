#pragma once
#include "prereq.hpp"
#include "vkctx.hpp"

class DemoApplication {
public:
    void run();

private:
    void _init();
    void _loop();
    void _cleanup();

private:
    GLFWwindow* _wnd;
    std::unique_ptr<VKContext> _vkctx;
};



