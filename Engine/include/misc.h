#ifndef ENGINE_MISC_H
#define ENGINE_MISC_H

#include "def.h"
#include "types.h"
#include "extern.h"

namespace Engine {
std::string ENGINE_API GetTimeStr(std::string_view fmt = "%c", time_t time = 0,
                                  size_t buf_size = 128);
void ENGINE_API GetTimeStr(char *buf, size_t size, std::string_view fmt = "%c",
                           time_t time = 0);
std::string ENGINE_API GetKeyName(int key, int scancode);

void KeyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mode);
void TextInputCallback(GLFWwindow *window, unsigned int codepoint);
void CursorPositionCallback(GLFWwindow *window, double xpos, double ypos);
void CurosorEnterCallback(GLFWwindow *window, int entered);
void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
void ScrollCallback(GLFWwindow *window, double xoffset, double yoffset);
void DropCallback(GLFWwindow *window, int count, const char **paths);
void JoystickConnectCallback(int jid, int event);

} // namespace Engine

#endif // !ENGINE_MISC_H
