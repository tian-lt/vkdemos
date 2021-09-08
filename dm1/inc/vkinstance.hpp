#pragma once
#include "prereq.hpp"

struct VKInstance {
    explicit VKInstance(const char* app_name);
    ~VKInstance();
    VKInstance(const VKInstance&) = delete;
    VKInstance(VKInstance&&) noexcept = default;

    VkInstance instance;
};

namespace details {
#ifdef _DEBUG 
    constexpr const bool enable_validation_layers = true;
#else
    constexpr const bool enable_validation_layers = false;
#endif
    inline const std::vector<const char*> validation_layers = {
        "VK_LAYER_KHRONOS_validation"
    };
}


