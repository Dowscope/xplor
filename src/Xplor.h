#ifndef __XPLOR_H
#define __XPLOR_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Screen.h"

class Xplor
{
private:
    Screen* _mainScreen;
    void _init();
    void _mainLoop();
    void _cleanup();
public:
    Xplor();
    ~Xplor();
    void run();
};

#endif 
