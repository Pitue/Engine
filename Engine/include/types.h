#ifndef ENGINE_TYPES_H
#define ENGINE_TYPES_H

namespace Engine {

#ifdef UINT8_MAX
typedef uint8_t uint8f;
#else
#if sizeof(unsigned char) == 1
	typedef unsigned char uint8f;
#else 
#error Engine needs fixed 8bit integer
#endif
#endif

typedef uint_fast8_t uint8;
typedef uint_fast16_t uint16;

enum class InitFlags : uint8 {
	INIT_DEFAULT = 1ui8
};
#define ENGINE_INIT_EVERYTHING Engine::InitFlags::INIT_DEFAULT

#define ENGINE_VECTOR2 glm::tvec2
typedef glm::tvec2<int> Vector2i;
typedef glm::tvec2<unsigned int> Vector2ui;
typedef glm::tvec2<float> Vector2f;
typedef glm::tvec2<double> Vector2d;

enum class EventType : uint8 {
	UNDEFINDED = 0,
	KEY,
	TEXT,
	CURSOR_POSITION,
	CURSOR_ENTER,
	MOUSE_BUTTON,
	SCROLL,
	JOYSTICK_CONNECT,
	DROP,
	WINDOW_RESIZE
};

enum class WindowFlags : uint8 {
	RESIZEABLE = 0b00000001
};

} // namespace Engine

#endif // !ENGINE_TYPES_H
