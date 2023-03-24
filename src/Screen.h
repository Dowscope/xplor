#ifndef __SCREEN_H__
#define __SCREEN_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

class Screen
{
private:
    GLFWWindow* _mainWindow;
    void _initWindow();
    void _initVulkan();
public:
    Screen();
    ~Screen();
};

#endif
