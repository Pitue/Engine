#include "Shader.h"

namespace Engine {
Shader::Shader(GLenum shader_type, const char *src, bool compile/* = true*/)
    : src_{src}, compiled_{false}, shader_type_{shader_type}, ptr_{0} {
  if (compile)
    Compile();
}
Shader::~Shader() {
  if (ptr_)
    glDeleteShader(ptr_);
}
std::string Shader::Load() {
  std::string shader;
  if (std::filesystem::is_regular_file(src_)) {
    std::ifstream file(src_);
    if (!file.is_open()) {
      e_engine->Throw({"Couldn't open sahder file \"", src_, "\""});
    }

    uintmax_t size = std::filesystem::file_size(src_);
    shader.resize(size, '\0');
    file.read(shader.data(), size);

    file.close();
  } else {
    shader = src_;
  }
  return shader;
}
void Shader::Compile() {
  const char *src = Load().c_str();

  ptr_ = glCreateShader(shader_type_);
  glShaderSource(ptr_, 1, &src, NULL);
  glCompileShader(ptr_);

  int success = 0;
  glGetShaderiv(ptr_, GL_COMPILE_STATUS, &success);
  if (!success) {
    char info[512];
    glGetShaderInfoLog(ptr_, 512, NULL, info);
    e_engine->Throw({"Shader compilation failed: ", info});
  }
  compiled_ = true;
}
} // namespace Engine