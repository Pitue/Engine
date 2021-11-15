#include "misc.h"

namespace Engine {
void KeyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mode) {
  e_event_list.emplace_back(window, EventType::KEY, KeyEvent{ key, scancode, action, mode });
}
void TextInputCallback(GLFWwindow *window, unsigned int codepoint) {
  e_event_list.emplace_back(window, EventType::TEXT, TextEvent{ codepoint });
}
void CursorPositionCallback(GLFWwindow *window, double xpos, double ypos) {
  e_event_list.emplace_back(window, EventType::CURSOR_POSITION, CursorPositionEvent{ xpos, ypos });
}
void CurosorEnterCallback(GLFWwindow *window, int entered) {
  e_event_list.emplace_back(window, EventType::CURSOR_ENTER, CursorEnterEvent{ entered });
}
void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
  e_event_list.emplace_back(window, EventType::MOUSE_BUTTON, MouseButtonEvent{ button, action, mods });
}
void ScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
  e_event_list.emplace_back(window, EventType::SCROLL, ScrollEvent{ xoffset, yoffset });
}
void JoystickConnectCallback(int jid, int event) {
  e_event_list.emplace_back(nullptr, EventType::JOYSTICK_CONNECT, JoystickConnectEvent{ jid, event });
}
void DropCallback(GLFWwindow *window, int count, const char **paths) {
  e_event_list.emplace_back(window, EventType::DROP, DropEvent{ count, paths });
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

std::string ENGINE_API GetKeyName(int key, int scancode) {
  return std::string(glfwGetKeyName(key, scancode));
}
} // namespace Engine