#ifndef ENGINE_TYPES_H
#define ENGINE_TYPES_H

#include <cstdint>

namespace Engine {

#ifdef UINT8_MAX
typedef uint8_t uint8f;
#else

#endif
typedef uint_fast8_t uint8;

enum class InitFlags : uint8 {
	INIT_DEFAULT = 1ui8
};

#define ENGINE_INIT_EVERYTHING Engine::InitFlags::INIT_DEFAULT
} // namespace Engine

#endif // !ENGINE_TYPES_H
