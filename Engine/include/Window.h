#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include "def.h"
#include "types.h"
#include "Engine.h"
#include "extern.h"

#include "Event.h"
#include "Color.h"

namespace Engine {
class ENGINE_API Window {
  Vector2i size_;
  std::string title_;
  GLFWwindow *window_;

public:
  Window(Vector2i size, std::string title, WindowFlags flags,
         GLFWmonitor *monitor = nullptr);
  ~Window();
  inline operator GLFWwindow*() {
    return window_;
  } 

  inline void Clear(Color color = ENGINE_COLOR_WHITE) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
  }
  inline void SwapBuffer() {
    glfwSwapBuffers(window_);
  }
  inline void PollEvents() const {
    glfwPollEvents();
  }
  bool PullEvent(Event *evt);

  inline bool ShouldClose() const {
    return glfwWindowShouldClose(window_);
  }

  /*The viewport is set to (0,0, size_x, size_y) initially*/
  inline void set_viewport(glm::tmat2x2<int> viewport) {
    glViewport(viewport[0][0], viewport[0][1], viewport[1][0], viewport[1][1]);
  }
};
} // namespace Engine

#endif // ENGINE_WINDOW_H
