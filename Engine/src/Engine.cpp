#include "Engine.h"

namespace Engine {
  Engine::Engine() 
    : init_flags_{ 0 }
    , initialized_{ false }
    , error_callback_() {
  
  }
  Engine::~Engine() {
    if (e_engine) {
      delete e_engine;
      e_engine = nullptr;
    }
  }

  void Engine::Init(InitFlags flags) {
    init_flags_ = flags;
    if (static_cast<uint8>(flags) == 0) {
      Throw("No initialisation flags specified");
    }

    if (static_cast<uint8>(flags) & static_cast<uint8>(InitFlags::INIT_DEFAULT)) {
      if (glfwInit() == GLFW_FALSE) {
        const char* description = nullptr;
        int error_code = GLFW_NO_ERROR;
        while ((error_code = glfwGetError(&description)) != GLFW_NO_ERROR) {
          std::stringstream err;
          err << "glfw error(" << error_code << "): " << description;
          Throw(err.str());
        }
      }
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if defined(__APPLE__)
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    }

    initialized_ = true;
  }
  void Engine::Quit(bool force /*= false*/) {
    Log("Terminating Engine");
    if (static_cast<uint8>(init_flags_) & static_cast<uint8>(InitFlags::INIT_DEFAULT)) {
      glfwTerminate();
    }

    if (force) {
      abort();
    }
  }

  void Engine::Throw(std::string_view msg) {
    std::runtime_error exc(msg.data());
    if (!error_callback_) {
      throw exc;
    }
    else if (!error_callback_(exc)) {
      Quit(true);
    }
  }
  void Engine::Throw(std::initializer_list<std::string> msg) {
    std::stringstream ss;
    for (auto &str : msg) {
      ss << str;
    }
    Throw(ss.str());
  }
  void Engine::Log(std::string_view msg) {
#ifdef _DEBUG
    std::cout << msg << "\n";
#endif
  }


  std::string Engine::GetDescription() {
    std::stringstream str;

    str << "Engine ver. " << ENGINE_VERSION_STR_OS << "\n"
      << "Using libraries: \n"
      << "OpenGL ver. " << glGetString(GL_VERSION) << "\n"
      << "GLFW3 ver." << glfwGetVersionString() << "\n"
      << "glad\n"
      << PNG_HEADER_VERSION_STRING + sizeof(PNG_HEADER_VERSION_STRING[0])
      << "mpg123\n"
      << GLM_VERSION_MESSAGE << "\n"
      << LUA_VERSION << "\n";

    return str.str();
  }


  Engine *Engine::CreateEngine() {
    if (!e_engine)
      e_engine = new Engine();

    return e_engine;
  }
}