#include "Window.h"

namespace Engine {
Window::Window(Vector2i size, std::string title,
               GLFWmonitor *monitor)
    : size_(size), title_{std::move(title)}, window_{nullptr} {
  window_ = glfwCreateWindow(size_.x, size_.y, title_.c_str(), monitor, NULL);
  glfwMakeContextCurrent(window_);
  if (!window_) {
    const char *msg = nullptr;
    std::stringstream msg_ss;
    msg_ss << "GLFW error whilst creating window(" << glfwGetError(&msg)
           << "): " << msg;
    e_engine->Throw(msg_ss.str());
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
  glViewport(0, 0, size_.x, size_.y);

  e_engine->Log(e_engine->GetDescription());
}
Window::~Window() {}

bool Window::PullEvent(Event *evt) {
  if (e_event_list.size() > 0) {
    auto it = std::find_if(e_event_list.begin(), e_event_list.end(),
      [this](Event& e) { return e.window == window_; });
    if (it != e_event_list.end()) {
      *evt = *it;
      e_event_list.erase(it);
      return true;
    }
  }
  return false;
}
} // namespace Engine