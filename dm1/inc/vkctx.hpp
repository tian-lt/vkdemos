/*
 vkctx.hpp
 migrates the code snippets from [Vulkan Tutorial](https://vulkan-tutorial.com/) and put them together into
 VKContext so that we can reuse vulkan capabilities handly.
*/

#pragma once
#include "prereq.hpp"

class VKContext {
public:
    void initialize(GLFWwindow* window, const std::string& app_name, const std::string& engine_name, const std::string& rootpath);
    void uninitialize();
    void reset_swapchain();
    void draw_frame();
    void wait_for_device_idle();

private:
    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;
        bool isComplete() const {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };
    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    void create_instance();
    void create_validation_layer();
    void create_surface();
    void pick_physical_device();
    void create_device();
    void create_swapchain();
    void create_image_views();
    void create_render_pass();
    void create_pipeline();
    void create_framebuffers();
    void create_command_pool();
    void create_command_buffers();
    void create_sync_objects();

    void cleanup_swapchain();

    bool isDeviceSuitable(VkPhysicalDevice device) const;
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device) const;

private:
    static std::vector<const char*> validationLayers;
    static std::vector<const char*> deviceExtensions;
    static constexpr int max_frames_in_flight = 2;
    static bool enableValidationLayers;
    static bool checkValidationLayerSupport();
    static std::vector<const char*> getRequiredExtensions();
    static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device, VkSurfaceKHR surface);
    static bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
    static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
    static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
    static VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    static VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    static VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);
    static std::string readFile(const std::string& filename);
    static VkShaderModule createShaderModule(VkDevice device, const std::string& code);
    
private:
    std::string _app_name;
    std::string _engine_name;
    std::string _roopath;
    GLFWwindow* _window;

public:
    int _current_frame;
    VkInstance _inst;
    VkDebugUtilsMessengerEXT _dbgmsg;
    VkSurfaceKHR _surface;
    VkPhysicalDevice _pdev;
    VkDevice _device;
    VkQueue _graphics_queue;
    VkQueue _present_queue;
    VkSwapchainKHR _swapchain;
    std::vector<VkImage> _swapchain_imgs;
    VkFormat _swapchain_img_fmt;
    VkExtent2D _swapchain_ext;
    std::vector<VkImageView> _swapchain_img_views;
    std::vector<VkFramebuffer> _swapchain_framebuffers;
    VkRenderPass _render_pass;
    VkPipelineLayout _pipeline_layout;
    VkPipeline _pipeline;
    VkCommandPool _cmd_pool;
    std::vector<VkCommandBuffer> _cmd_buffers;
    std::vector<VkSemaphore> _img_available_smphr;
    std::vector<VkSemaphore> _render_finished_smphr;
    std::vector<VkFence> _inflight_fences;
    std::vector<VkFence> _imgs_inflight;
    bool _frame_buffer_resized;
};
