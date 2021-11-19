#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "def.h"
#include "types.h"
#include "misc.h"
#include "extern.h"

#pragma warning (disable : 4251)

namespace Engine {
typedef ENGINE_API std::function<bool(std::exception)> error_callback_fn;

class ENGINE_API Engine {
	bool initialized_;
	error_callback_fn error_callback_;
	InitFlags init_flags_;
	std::vector<int> vec_int_;

	Engine();
public:
	~Engine();
	Engine(const Engine& other) = delete;
	Engine& operator = (const Engine& other) = delete;

	void Init(InitFlags flags);
	void Quit(bool force = false);
	
	void Throw(std::string_view msg);
	void Throw(std::initializer_list<std::string> msg);
	void Log(std::string_view msg);

	std::string GetDescription();

	inline void set_error_callback(error_callback_fn fnct) {
		error_callback_ = fnct;
	}

	static Engine* CreateEngine();
};
} // namespace Engine

#endif // !ENGINE_ENGINE_H