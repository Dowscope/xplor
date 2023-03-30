#ifndef __SCREEN_H__
#define __SCREEN_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <cstring>

class Screen
{
private:
    GLFWwindow *_mainWindow;
    VkInstance _instance;
    VkDebugUtilsMessengerEXT _debugMessenger;

    const std::vector<const char *> _validationLayers = {
        "VK_LAYER_KHRONOS_validation"};

    void _initWindow();
    void _initVulkan();
    void setupDebugMessenger();
    void _createInstance();
    bool _checkValidationLayerSupport();
    std::vector<const char *> _getRequiredExtensions();
    VkResult _createDebugUtilsMessengerEXT(  
        VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger
    );
    void _destroyDebugUtilsMessengerEXT(
        VkInstance instance,
        VkDebugUtilsMessengerEXT debugMessenger,
        const VkAllocationCallbacks* pAllocator
    );

public:
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
        void *pUserData);
    const uint32_t width = 800;
    const uint32_t height = 600;

    bool enableValidationLayers = true;

    Screen();
    ~Screen();

    bool shouldWindowClose();
    void pollEvents();
};

#endif
