#include "Screen.h"

Screen::Screen()
{
   _initWindow();
   _initVulkan();
}

Screen::~Screen()
{
    std::cout << "Shutting down screen..." << std::endl;

    std::cout << "Destroying VK Instance...";
    vkDestroyInstance(_instance, nullptr);
    std::cout << "OK" << std::endl;

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
    std::cout << "Creating Instance... ";

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Xplor";
    appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    // Checking for extension support
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    // Display the available extensions
    // std::cout << "available extensions:\n";
    // for (const auto& extension : extensions) {
    //     std::cout << '\t' << extension.extensionName << '\n';
    // }

    if (vkCreateInstance(&createInfo, nullptr, &_instance) != VK_SUCCESS){
        throw std::runtime_error("Failed to create instance");
    }

    std::cout << "OK" << std::endl;
}
