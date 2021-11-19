#include "ShaderProgram.h"

Engine::ShaderProgram::ShaderProgram()
	: shader_(), ptr_{ 0 }, linked_{ false } {
	ptr_ = glCreateProgram();
}

Engine::ShaderProgram::~ShaderProgram() {
	if (ptr_)
		glDeleteProgram(ptr_);
}

void Engine::ShaderProgram::AttachShader(GLuint shader) {
	if (std::find(shader_.begin(), shader_.end(), shader) == shader_.end()) {
		shader_.emplace_back(shader);
		glAttachShader(ptr_, shader);
	}
}

void Engine::ShaderProgram::DetachShader(GLuint shader) {
	auto it = std::find(shader_.begin(), shader_.end(), shader);
	if (it != shader_.end()) {
		shader_.erase(it);
		glDetachShader(ptr_, shader);
	}
}

void Engine::ShaderProgram::Link() {
	glLinkProgram(ptr_);

	int success = 0;
	glGetProgramiv(ptr_, GL_LINK_STATUS, &success);
	if (!success) {
		char info[512];
		glGetProgramInfoLog(ptr_, 512, NULL, info);
		e_engine->Throw({ "Couldn't link shader program: ", info });
	}
	linked_ = true;
}

void Engine::ShaderProgram::Delete() {
	if (ptr_) {
		glDeleteProgram(ptr_);
		ptr_ = 0;
	}
}
