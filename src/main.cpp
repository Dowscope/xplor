
#include <iostream>
#include "Xplor.h"

int main(int argc, char const *argv[])
{
    std::cout << "Starting Xplor..." << std::endl;
    Xplor xplor;

    try {
        xplor.run();
    }
    catch (const std::exception e){
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
