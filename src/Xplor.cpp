#include "Xplor.h"

Xplor::Xplor()
{
   
}

Xplor::~Xplor()
{
    std::cout << "Shutting down XPLOR... " << std::endl;
    std::cout << "XPLOR shut down successfully" << std::endl;
}

void Xplor::run()
{
    _init();
    _mainLoop();
    _cleanup();
}

void Xplor::_init()
{
    std::cout << "Starting Initializatrion" << std::endl;
    _mainScreen = new Screen();
}

void Xplor::_mainLoop()
{
}

void Xplor::_cleanup()
{
    delete _mainScreen;
}
