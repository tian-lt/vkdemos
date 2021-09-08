#pragma once
#include "prereq.hpp"
#include "vkinstance.hpp"
#include "vksurface.hpp"
#include "vkpdevice.hpp"
#include "vkldevice.hpp"

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
    std::unique_ptr<VKSurface> _vksurface;
    std::unique_ptr<VKPhysicalDevice> _vkpdev;
    std::unique_ptr<VKLogicalDevice> _vkdev;
};



