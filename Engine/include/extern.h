#ifndef ENGINE_EXTERN_H
#define ENGINE_EXTERN_H

#include "types.h"

#include "Event.h"

namespace Engine {
class Engine;

extern Engine *e_engine;
extern std::list<Event> e_event_list;
} // namespace Engine

#endif // !ENGINE_EXTERN_H
