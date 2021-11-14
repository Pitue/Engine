#ifndef ENGINE_MISC_H
#define ENGINE_MISC_H

#include "def.h"
#include "types.h"
#include "extern.h"

namespace Engine {
void ENGINE_API Throw(std::string_view msg);
void ENGINE_API Log(std::string_view msg);

std::string ENGINE_API GetTimeStr(std::string_view fmt = "%c", time_t time = 0,
                                  size_t buf_size = 128);
void ENGINE_API GetTimeStr(char *buf, size_t size, std::string_view fmt = "%c",
                           time_t time = 0);

std::string ENGINE_API GetDescription();

void ENGINE_API SetErrorCallback(std::function<bool(std::exception)> fnct);

void ENGINE_API Init(InitFlags flags);
void ENGINE_API Quit(bool force = false);

} // namespace Engine

#endif // !ENGINE_MISC_H
