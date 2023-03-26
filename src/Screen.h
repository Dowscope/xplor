#ifndef __SCREEN_H__
#define __SCREEN_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

class Screen
{
private:
    GLFWwindow* _mainWindow;
    VkInstance _instance;

    void _initWindow();
    void _initVulkan();
    void _createInstance();
public:
    const uint32_t width = 800;
    const uint32_t height = 600;
    Screen();
    ~Screen();

    bool shouldWindowClose();
    void pollEvents();
};

#endif
