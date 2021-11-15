#ifndef ENGINE_COLOR_H
#define ENGINE_COLOR_H

namespace Engine {
	struct Color {
		float r, g, b, a;
	};

#define ENGINE_COLOR_WHITE ::Engine::Color{1.f, 1.f, 1.f, 1.f}
}

#endif