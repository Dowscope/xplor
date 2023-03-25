#include "Xplor.h"

Xplor::Xplor()
{
   
}

Xplor::~Xplor()
{
    std::cout << "Shutting down XPLOR... " << std::endl;
    
    delete _mainScreen;

    std::cout << "XPLOR shut down successfully" << std::endl;
}

void Xplor::run()
{
    _init();
    _mainLoop();
}

void Xplor::_init()
{
    std::cout << "Starting Initializatrion" << std::endl;
    _mainScreen = new Screen();
}

void Xplor::_mainLoop()
{
    while(!_mainScreen->shouldWindowClose()){
        _mainScreen->pollEvents();
    }
}
