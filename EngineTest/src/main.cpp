#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <Engine/include.h>

int main() {
    std::cout << "Hello World: ";
    Engine::PrintMessage();
    std::cout << "\n";

    auto i = new int{ 8 };

    glm::tvec3<int> vec;
    
    _CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}
