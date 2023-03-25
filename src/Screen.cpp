#include "Screen.h"

Screen::Screen()
{
   _initWindow();
   _initVulkan();
}

Screen::~Screen()
{
    std::cout << "Shutting down screen..." << std::endl;

    std::cout << "Destroying windows...";
    glfwDestroyWindow(_mainWindow);
    std::cout << "OK" << std::endl;

    std::cout << "Terminating GLFW...";
    glfwTerminate();
    std::cout << "OK" << std::endl;
   
    std::cout << "Screen shut down successfully" << std::endl;
}

bool Screen::shouldWindowClose()
{
    return glfwWindowShouldClose(_mainWindow);
}

void Screen::pollEvents()
{
    glfwPollEvents();
}

void Screen::_initWindow()
{
    std::cout << "Initializing GLFW... ";
    if (glfwInit() == GL_FALSE){
        std::cout << "Error Initializing GLFW" << std::endl;
    }
    std::cout << "OK" << std::endl;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    std::cout << "Creating Window... ";
    _mainWindow = glfwCreateWindow(width, height, "XPLOR", nullptr, nullptr);
    if (!_mainWindow){
        std::cout << "Error Creating Window" << std::endl;
    }
    std::cout << "OK" << std::endl;
}

void Screen::_initVulkan()
{
    std::cout << "Initializing Vulkan... " << std::endl;

    _createInstance();

    std::cout << "Initialized Vulkan Successfully" << std::endl;
}

void Screen::_createInstance()
{
}
