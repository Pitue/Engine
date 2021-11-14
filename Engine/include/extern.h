#ifndef ENGINE_EXTERN_H
#define ENGINE_EXTERN_H

#include "types.h"

namespace Engine {
	extern bool initialized;
	extern bool error_handled;
	extern std::function<bool(std::exception)> error_callback;
	extern InitFlags init_flags;
}

#endif // !ENGINE_EXTERN_H
