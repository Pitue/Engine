#ifndef ENGINE_DEF_H
#define ENGINE_DEF_H

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else 
#define ENGINE_API __declspec(dllimport)
#endif

#endif // !ENGINE_DEF_H
