#include "vkpdevice.hpp"

namespace details {
    QueueFamilyIndices find_queue_families(VkPhysicalDevice device, VkSurfaceKHR surface) {
        QueueFamilyIndices indices;
        uint32_t queue_family_count = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, nullptr);
        std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, queue_families.data());
        int i = 0;
        for (const auto& queue_family : queue_families) {
            if (queue_family.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                indices.graphics_family = i;
            }
            VkBool32 present_support = false;
            vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &present_support);
            if (present_support) {
                indices.present_family = i;
            }
            if (indices.is_complete()) {
                break;
            }
            ++i;
        }
        return indices;
    }

    bool is_device_suitable(VkPhysicalDevice device, VkSurfaceKHR surface) {
        QueueFamilyIndices indices = find_queue_families(device, surface);
        return indices.is_complete();
    }
}

VKPhysicalDevice::VKPhysicalDevice(const VKInstance& inst) {
    uint32_t device_count = 0;
    vkEnumeratePhysicalDevices(inst.instance, &device_count, nullptr);
    if (device_count == 0) {
        throw std::runtime_error("failed to find GPUs with Vulkan support.");
    }
    devices.resize(device_count);
    vkEnumeratePhysicalDevices(inst.instance, &device_count, devices.data());
}

VkPhysicalDevice VKPhysicalDevice::pick(const VKSurface& surface) const {
    VkPhysicalDevice result = VK_NULL_HANDLE;
    for (const auto& device : devices) {
        if (details::is_device_suitable(device, surface.surface)) {
            result = device;
            break;
        }
    }
    if (result == VK_NULL_HANDLE) {
        throw std::runtime_error("failed to find a suitable GPU!");
    }
    return result;
}



