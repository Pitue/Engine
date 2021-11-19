#include "Window.h"
#include <glm/mat2x2.hpp>

namespace Engine {
Window::Window(Vector2i size, std::string title, WindowFlags flags,
               GLFWmonitor *monitor)
    : size_(size), title_{std::move(title)}, window_{nullptr} {

  if ((uint8)flags & (uint8)WindowFlags::RESIZEABLE) {
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
  } else {
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  }

  window_ = glfwCreateWindow(size_.x, size_.y, title_.c_str(), monitor, NULL);
  if (!window_) {
    const char *msg = nullptr;
    std::stringstream msg_ss;
    msg_ss << "GLFW error whilst creating window(" << glfwGetError(&msg)
           << "): " << msg;
    e_engine->Throw(msg_ss.str());
  }
  glfwMakeContextCurrent(window_);

  uint8 v_flags = static_cast<uint8>(flags);
  if (v_flags & (uint8)WindowFlags::RESIZEABLE) {
    glfwSetFramebufferSizeCallback(
        window_, (GLFWframebuffersizefun)FramebufferSizeCallback);
  }

  glfwSetKeyCallback(window_, (GLFWkeyfun)KeyCallback);
  glfwSetCharCallback(window_, (GLFWcharfun)TextInputCallback);
  glfwSetCursorPosCallback(window_, (GLFWcursorposfun)CursorPositionCallback);
  glfwSetCursorEnterCallback(window_, (GLFWcursorenterfun)CurosorEnterCallback);
  glfwSetMouseButtonCallback(window_, (GLFWmousebuttonfun)MouseButtonCallback);
  glfwSetScrollCallback(window_, (GLFWscrollfun)ScrollCallback);
  glfwSetJoystickCallback((GLFWjoystickfun)JoystickConnectCallback);
  glfwSetDropCallback(window_, (GLFWdropfun)DropCallback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    e_engine->Throw("glad: couldn't load gl loader");
  }

  e_engine->Log(e_engine->GetDescription());
}
Window::~Window() {}

bool Window::PullEvent(Event *evt) {
  if (!e_event_list.empty()) {
    auto it = std::find_if(e_event_list.begin(), e_event_list.end(),
                           [this](Event &e) { return e.window == window_; });
    if (it != e_event_list.end()) {
      *evt = *it;
      e_event_list.erase(it);
      return true;
    }
  }
  return false;
}
} // namespace Engine