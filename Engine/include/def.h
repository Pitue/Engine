#ifndef ENGINE_DEF_H
#define ENGINE_DEF_H

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else 
#define ENGINE_API __declspec(dllimport)
#endif

#define ENGINE_MAJOR 0
#define ENGINE_MINOR 0
#define ENGINE_PATCHLEVEL 0

#define ENGINE_VERSION_STR "0.0.0"
#define ENGINE_VERSION_STR_OS ENGINE_MAJOR << "." << ENGINE_MINOR << "." << ENGINE_PATCHLEVEL

#endif // !ENGINE_DEF_H
