#include "sys/shader.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>

using namespace sys;

shader::shader(GLuint type, const std::string &file) {
  // Create shader handle
  handle = glCreateShader(type);
  if (0 == handle) throw std::runtime_error("Unable to create shader handle");

  // Load source file
  std::ifstream source_file(file.c_str(), std::ifstream::in);
  std::string source(
      (std::istreambuf_iterator<char>(source_file)), 
      std::istreambuf_iterator<char>());
  const GLchar* actual_source[] = { source.c_str() };
  glShaderSource(handle, 1, actual_source, NULL);

  // Compile shader
  glCompileShader(handle);

  GLint compilation_result = 0;
  glGetShaderiv(handle, GL_COMPILE_STATUS, &compilation_result);
  if (GL_FALSE == compilation_result) {
    std::cout << "Vertex shader compilation failed" << std::endl;

    GLint compilation_log_length;
    glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &compilation_log_length);
    if (compilation_log_length > 0) {
      std::vector<char> log(compilation_log_length);
      glGetShaderInfoLog(handle, compilation_log_length, 0, &log[0]);
      std::cout << &log[0] << std::endl;
    }

    throw std::runtime_error("Vertex shader compilation failed");
  } else {
    std::cout << "Shader " << file << " compiled successfully" << std::endl;
  }
}

GLuint shader::get_handle() const {
  return handle;
}

shader::~shader() {

}
