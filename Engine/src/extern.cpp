#include "extern.h"

namespace Engine {
	bool initialized = false;
	bool error_handled = false;
	std::function<bool(std::exception)> error_callback{};
	InitFlags init_flags{};
}