#ifndef __SCREEN_H__
#define __SCREEN_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

class Screen
{
private:
    GLFWwindow* _mainWindow;
    VkInstance* _mainInstance;
    
    void _initWindow();
    void _initVulkan();
    void _createInstance();
public:
    const int width = 800;
    const int height = 600;
    Screen();
    ~Screen();

    bool shouldWindowClose();
    void pollEvents();
};

#endif
