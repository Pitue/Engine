#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include "def.h"
#include "types.h"

namespace Engine {
class ENGINE_API Window {
	ENGINE_VECTOR2<size_t> size_;
	std::string_view title_;

	public:
		Window(ENGINE_VECTOR2<size_t> size, std::string_view title) {
		}
};
} // namespace Engine

#endif // ENGINE_WINDOW_H
