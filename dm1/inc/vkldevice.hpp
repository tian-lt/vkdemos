#pragma once
#include "vkinstance.hpp"
#include "vkpdevice.hpp"
#include "vksurface.hpp"

struct VKLogicalDevice {
    explicit VKLogicalDevice(const VKPhysicalDevice& pdevice, const VKSurface& surface);
    ~VKLogicalDevice() noexcept;
    VKLogicalDevice(const VKLogicalDevice&) = delete;
    VKLogicalDevice(VKLogicalDevice&&) = default;

    VkQueue get_graphics_queue() const { return _graphics_queue; };
    VkQueue get_present_queue() const { return _present_queue; };
    VkDevice device;
    uint32_t queue_family_index;

    VkQueue _graphics_queue;
    VkQueue _present_queue;
};


