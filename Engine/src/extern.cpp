#include "extern.h"

#include "Engine.h"

namespace Engine {
	Engine *e_engine = nullptr;
	std::list<Event> e_event_list(0);
}