#pragma once
#include "prereq.hpp"
#include "vkinstance.hpp"

struct VKSurface {
    explicit VKSurface(const VKInstance& inst, GLFWwindow* window)
        : surface(VK_NULL_HANDLE)
        , _inst(inst.instance) {
        if (VK_SUCCESS != glfwCreateWindowSurface(inst.instance, window, nullptr, &surface)) {
            throw std::runtime_error("failed to create window surface.");
        }
    }
    ~VKSurface() {
        vkDestroySurfaceKHR(_inst, surface, nullptr);
    }

    VkSurfaceKHR surface;
    VkInstance _inst;
};



