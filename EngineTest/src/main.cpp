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

bool ErrorCallback(std::exception ex) {
  std::cout << "In error callback";
  return false;
}

int main() {
  using namespace std::chrono_literals;

#ifdef DUMP_MEMORY_LEAKS
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
#endif

  try {
    Engine::Engine *engine = Engine::Engine::CreateEngine();
    engine->set_error_callback((Engine::error_callback_fn)ErrorCallback);

    engine->Init(ENGINE_INIT_EVERYTHING);

    Engine::Window window({ 500, 500 }, "Hello World!", Engine::WindowFlags::RESIZEABLE);
    Engine::Event evt;
    bool running = true;
    while (running && !window.ShouldClose()) {
      window.PollEvents();
      while (window.PullEvent(&evt)) {
        if (evt.type == Engine::EventType::KEY) {
          if (evt.key_event.action == GLFW_PRESS) {
            if (evt.key_event.key == GLFW_KEY_ESCAPE) {
              running = false;
              break;
            }
          }
        }
      }      

      window.Clear(ENGINE_COLOR_BLACK);
      window.SwapBuffer();
    }

    engine->Quit();
  } catch (std::exception &ex) {
    std::cerr << "catched excpetion at main: \"" << ex.what() << "\"\n";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
