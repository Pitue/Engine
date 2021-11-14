#include "misc.h"

namespace Engine {
void Throw(std::string_view msg) {
  std::runtime_error exc(msg.data());
  if (!error_handled) {
    throw exc;
  }
  else if (!error_callback(exc)) {
    Quit(true);
  }
}
void Log(std::string_view msg) {
#ifdef _DEBUG
  std::cout << msg << "\n";
#endif
}

std::string GetTimeStr(std::string_view fmt, time_t time, size_t buf_size) {
  if (!time)
    std::time(&time);
  std::string ret(buf_size, '\0');

  tm *tm = std::localtime(&time);
  std::strftime(ret.data(), ret.size(), fmt.data(), tm);
  return ret;
}
void GetTimeStr(char *buf, size_t size, std::string_view fmt, time_t time) {
  if (!time)
    std::time(&time);
  tm *tm = std::localtime(&time);
  std::strftime(buf, size, fmt.data(), tm);
}

std::string GetDescription() {
  std::stringstream str;

  str << "Engine ver. " << ENGINE_VERSION_STR_OS << "\n"
    << "Using libraries: \n"
    << "OpenGL ver. " << glGetString(GL_VERSION) << "\n"
    << "GLFW3 ver." << glfwGetVersionString() << "\n"
    << "glad\n"
    << "libpng ver. " << PNG_HEADER_VERSION_STRING
    << "mpg123\n"
    << GLM_VERSION_MESSAGE << "\n"
    << LUA_VERSION << "\n";

  return str.str();
}

void ENGINE_API SetErrorCallback(std::function<bool(std::exception)> fnct) {
  error_handled = true;
  error_callback = fnct;
}

void Init(InitFlags flags) {
  init_flags = flags;
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
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  }

  initialized = true;
}
void Quit(bool force /*= false*/) {
  Log("Terminating Engine");
  if (static_cast<uint8>(init_flags) & static_cast<uint8>(InitFlags::INIT_DEFAULT)) {
    glfwTerminate();
  }
  
  if (force) {
    abort();
  }
}
} // namespace Engine