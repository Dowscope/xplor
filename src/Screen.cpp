#include "Screen.h"

Screen::Screen()
{
   _initVulkan();
}

Screen::~Screen()
{
   std::cout << "Shutting down screen..." << std::endl;
    std::cout << "Screen shut down successfully" << std::endl;
}

void Screen::_initWindow()
{
    std::cout << "Initializing GLFW" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    _mainWindow = glfwCreateWindow(800,600, "XPLOR", nullptr, nullptr);
}

void Screen::_initVulkan()
{
    std::cout << "Initializing Vulkan" << std::endl;
}


