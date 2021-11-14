#include "misc.h"

namespace Engine {
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

void ENGINE_API Init(uint8 flags) {
  initialized = true;
}
} // namespace Engine