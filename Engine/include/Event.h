#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H

#include "def.h"
#include "types.h"

namespace Engine {

struct ENGINE_API KeyEvent {
  int key, scancode, action, mode;
};
struct ENGINE_API TextEvent {
  unsigned int codepoint;
};
struct ENGINE_API CursorPositionEvent {
  double x, y;
};
struct ENGINE_API CursorEnterEvent {
  int entered;
};
struct ENGINE_API MouseButtonEvent {
  int button, action, mods;
};
struct ENGINE_API ScrollEvent {
  double offsetx, offsety;
};
struct ENGINE_API JoystickConnectEvent {
  int jid, event;
};
struct ENGINE_API DropEvent {
  int count;
  const char **paths;
};

struct ENGINE_API Event {
  GLFWwindow* window;
  EventType type;

  union {
    KeyEvent key_event;
    TextEvent text_event;
    CursorPositionEvent cursor_position_event;
    CursorEnterEvent cursor_enter_event;
    MouseButtonEvent mouse_button_event;
    ScrollEvent scroll_event;
    JoystickConnectEvent joystick_connect_event;
    DropEvent drop_event;
  };

  Event();
  Event(GLFWwindow* window, EventType event);
  Event(GLFWwindow* window, EventType event, KeyEvent evt);
  Event(GLFWwindow* window, EventType event, TextEvent evt);
  Event(GLFWwindow* window, EventType event, CursorPositionEvent evt);
  Event(GLFWwindow* window, EventType event, CursorEnterEvent evt);
  Event(GLFWwindow* window, EventType event, MouseButtonEvent evt);
  Event(GLFWwindow* window, EventType event, ScrollEvent evt);
  Event(GLFWwindow* window, EventType event, JoystickConnectEvent evt);
  Event(GLFWwindow* window, EventType event, DropEvent evt);
};

} // namespace Engine

#endif // ENGINE_EVENT_H