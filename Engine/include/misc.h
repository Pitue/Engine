#ifndef ENGINE_MISC_H
#define ENGINE_MISC_H

#include "def.h"
#include "types.h"
#include "extern.h"

namespace Engine {
std::string ENGINE_API GetTimeStr(std::string_view fmt = "%c", time_t time = 0, size_t buf_size = 128);
void ENGINE_API GetTimeStr(char* buf, size_t size, std::string_view fmt = "%c", time_t time = 0);

void ENGINE_API Init(uint8 flags);
} // namespace Engine

#endif // !ENGINE_MISC_H
