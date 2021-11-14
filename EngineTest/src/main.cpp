#include <iostream>

#ifdef _MSC_VER
#ifdef _DEBUG
#define DUMP_MEMORY_LEAKS
#endif
#endif

#ifdef DUMP_MEMORY_LEAKS

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#endif

#include <Engine/include.h>

int main() {
  using namespace std::chrono_literals;

#ifdef DUMP_MEMORY_LEAKS
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
#endif

  try {
    while (1) {
      std::cout << "It is currently: " << Engine::GetTimeStr() << "\n";
      std::this_thread::sleep_for(500ms);
    }
  } catch (std::exception &ex) {
    std::cerr << "catched excpetion at main: \"" << ex.what() << "\"\n";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
