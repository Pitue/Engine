#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include "extern.h"
#include "def.h"

#include"Engine.h"

namespace Engine {
	class ENGINE_API Shader {
		GLenum shader_type_;
		const char *src_;
		GLuint ptr_;

		bool compiled_;
	public:
		Shader(GLenum shader_type, const char *src, bool compile = true);
		~Shader();

		operator bool() const {
			return compiled_;
		}

		std::string Load();
		void Compile();

		inline void Delete() {
			if (ptr_) {
				glDeleteShader(ptr_);
				ptr_ = 0;
			}
		}

		inline GLuint get_ptr() const {
			return ptr_;
		}
	};
}

#endif // !ENGINE_SHADER_H