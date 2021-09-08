#include <set>
#include "vkldevice.hpp"

VKLogicalDevice::VKLogicalDevice(const VKPhysicalDevice& pdevice, const VKSurface& surface)
    : device(VK_NULL_HANDLE)
    , queue_family_index(0)
    , _graphics_queue(VK_NULL_HANDLE)
    , _present_queue(VK_NULL_HANDLE){
    auto pdev = pdevice.pick(surface);
    auto indices = details::find_queue_families(pdev, surface.surface);

    std::vector<VkDeviceQueueCreateInfo> queue_create_infos;
    std::set<uint32_t> unique_queue_families = {indices.graphics_family.value(), indices.present_family.value()};

    float queue_priority = 1.f;
    for (uint32_t queue_family : unique_queue_families) {
        VkDeviceQueueCreateInfo queue_create_info{};
        queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queue_create_info.queueFamilyIndex = queue_family;
        queue_create_info.queueCount = 1;
        queue_create_info.pQueuePriorities = &queue_priority;
        queue_create_infos.emplace_back(std::move(queue_create_info));
    }

    VkPhysicalDeviceFeatures dev_features{};
    VkDeviceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    create_info.pQueueCreateInfos = queue_create_infos.data();
    create_info.queueCreateInfoCount = static_cast<uint32_t>(queue_create_infos.size());
    create_info.pEnabledFeatures = &dev_features;
    create_info.enabledExtensionCount = 0;

    if (details::enable_validation_layers) {
        create_info.enabledLayerCount = static_cast<uint32_t>(details::validation_layers.size());
        create_info.ppEnabledLayerNames = details::validation_layers.data();
    }
    else {
        create_info.enabledLayerCount = 0;
    }

    if (VK_SUCCESS != vkCreateDevice(pdev, &create_info, nullptr, &device)) {
        throw std::runtime_error("failed to create logical device!");
    }

    vkGetDeviceQueue(device, indices.graphics_family.value(), 0, &_graphics_queue);
    vkGetDeviceQueue(device, indices.present_family.value(), 0, &_present_queue);
}

VKLogicalDevice::~VKLogicalDevice() {
    vkDestroyDevice(device, nullptr);
}




