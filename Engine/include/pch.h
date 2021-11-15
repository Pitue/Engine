// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <exception>
#include <queue>

#include <thread>
#include <atomic>
#include <condition_variable>
#include <future>

#include <ctime>
#include <cstdint>
#include <climits>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <libpng16/png.h>
#include <mpg123.h>

#include <glm/common.hpp>

#include <lua.hpp>

#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN10                   
#endif

#include <asio.hpp>
#include <cryptopp/whrlpool.h>
#include <cryptopp/serpent.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>

#include <fmt/format.h>
#include <utf8cpp/utf8.h>
#include <magic_enum.hpp>
#include <zlib.h>

#endif //PCH_H
