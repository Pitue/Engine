#include "Event.h"

Engine::Event::Event() 
  : window{ nullptr }
  , type{ EventType::UNDEFINDED } {}

Engine::Event::Event(GLFWwindow* window, EventType event)
  : window{window}
  , type{event} {
}

Engine::Event::Event(GLFWwindow *window, EventType event, KeyEvent evt) 
  : Event(window, event) {
  key_event = std::move(evt);
}

Engine::Event::Event(GLFWwindow *window, EventType event, TextEvent evt)
  : Event(window, event) {
  text_event = std::move(evt);
}

Engine::Event::Event(GLFWwindow *window, EventType event,
                     CursorPositionEvent evt) 
  : Event(window, event) {
  cursor_position_event = std::move(evt);
}

Engine::Event::Event(GLFWwindow *window, EventType event,
                     CursorEnterEvent evt) 
  : Event(window, event) {
  cursor_enter_event = std::move(evt);
}

Engine::Event::Event(GLFWwindow *window, EventType event,
                     MouseButtonEvent evt) 
  : Event(window, event) {
  mouse_button_event = std::move(evt);
}

Engine::Event::Event(GLFWwindow *window, EventType event, ScrollEvent evt) 
  : Event(window, event) {
  scroll_event = std::move(evt);
}

Engine::Event::Event(GLFWwindow *window, EventType event,
                     JoystickConnectEvent evt) 
  : Event(window, event) {
  joystick_connect_event = std::move(evt);
}

Engine::Event::Event(GLFWwindow *window, EventType event, DropEvent evt) 
  : Event(window, event) {
  drop_event = std::move(evt);
}


