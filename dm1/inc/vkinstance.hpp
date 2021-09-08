#pragma once
#include "vulkan/vulkan.hpp"
#include "GLFW/glfw3.h"

struct VKInstance {
    explicit VKInstance(const char* app_name);
    ~VKInstance();
    VKInstance(const VKInstance&) = delete;
    VKInstance(VKInstance&&) noexcept = default;

    VkInstance instance;
};


