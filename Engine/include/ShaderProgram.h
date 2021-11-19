#ifndef ENGINE_SHADER_PROGRAM_H
#define ENGINE_SHADER_PROGRAM_H

#include "extern.h"
#include "Engine.h"

namespace Engine {

class ShaderProgram {
	std::vector<GLuint> shader_;
	GLuint ptr_;

	bool linked_;
public:
	ShaderProgram();
	~ShaderProgram();

	inline operator bool() const {
		return linked_;
	}

	void AttachShader(GLuint shader);
	void DetachShader(GLuint shader);

	void Link();
	void Delete();

	inline void Use() const {
		glUseProgram(ptr_);
	}
};

} // namespace Engine

#endif // !ENGINE_SHADER_PROGRAM_H