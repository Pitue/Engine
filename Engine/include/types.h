#ifndef ENGINE_TYPES_H
#define ENGINE_TYPES_H

#include "pch.h"
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

#define ENGINE_VECTOR2 glm::tvec2
typedef glm::tvec2<int> Vector2i;
typedef glm::tvec2<int> Vector2ui;
typedef glm::tvec2<int> Vector2f;
typedef glm::tvec2<int> Vector2d;



#define ENGINE_INIT_EVERYTHING Engine::InitFlags::INIT_DEFAULT
} // namespace Engine

#endif // !ENGINE_TYPES_H
