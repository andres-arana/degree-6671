#include "sys/shader_program.h"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace sys;

shader_program::shader_program(
    vertex_shader *vertex,
    fragment_shader *fragment) :
  vertex(vertex),
  fragment(fragment) {

  handle = glCreateProgram();
  if (0 == handle) 
    throw std::runtime_error("Unable to create shader program handle");

  glAttachShader(handle, vertex->get_handle());
  glAttachShader(handle, fragment->get_handle());
  glLinkProgram(handle);

  GLint status;
  glGetProgramiv(handle, GL_LINK_STATUS, &status);
  if (GL_FALSE == status) {
    std::cout << "Shader program link failed" << std::endl;

    GLint log_length;
    glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &log_length);
    if (log_length > 0) {
      std::vector<char> log(log_length);
      glGetProgramInfoLog(handle, log_length, 0, &log[0]);
      std::cout << &log[0] << std::endl;
    }

    throw std::runtime_error("Unable to link shader program");
  } else {
    std::cout << "Shader program linked successfully" << std::endl;
  }
}

void shader_program::use() const {
  glUseProgram(handle);
}

shader_param shader_program::get_uniform_param(const char* name) const {
  GLint param_handle = glGetUniformLocation(handle, name);
  return shader_param(param_handle);
}

shader_program::~shader_program() {

}
