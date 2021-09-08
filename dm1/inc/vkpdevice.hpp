#pragma once
#include "prereq.hpp"
#include "vkinstance.hpp"
#include "vksurface.hpp"

struct VKPhysicalDevice {
    explicit VKPhysicalDevice(const VKInstance& inst);
    VkPhysicalDevice pick(const VKSurface& surface) const;
    std::vector<VkPhysicalDevice> devices;
};

namespace details {
    struct QueueFamilyIndices {
        std::optional<uint32_t> graphics_family;
        std::optional<uint32_t> present_family;

        bool is_complete() const {
            return graphics_family.has_value() && present_family.has_value();
        }
    };

    QueueFamilyIndices find_queue_families(VkPhysicalDevice device, VkSurfaceKHR surface);
}




