#include "sys/shaders/shader.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>

sys::shaders::Shader::Shader(GLuint type, const std::string &file) {
  // Create shader handle
  handle = glCreateShader(type);
  if (0 == handle) throw std::runtime_error("Unable to create shader handle");

  // Load source file
  std::ifstream sourceFile(file.c_str(), std::ifstream::in);
  std::string source(
      (std::istreambuf_iterator<char>(sourceFile)), 
      std::istreambuf_iterator<char>());
  const GLchar* actualSource[] = { source.c_str() };
  glShaderSource(handle, 1, actualSource, NULL);

  // Compile shader
  glCompileShader(handle);

  GLint compilationResult = 0;
  glGetShaderiv(handle, GL_COMPILE_STATUS, &compilationResult);
  if (GL_FALSE == compilationResult) {
    std::cout << "Vertex shader compilation failed" << std::endl;

    GLint compilationLogLength;
    glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &compilationLogLength);
    if (compilationLogLength > 0) {
      std::vector<char> log(compilationLogLength);
      glGetShaderInfoLog(handle, compilationLogLength, 0, &log[0]);
      std::cout << &log[0] << std::endl;
    }

    throw std::runtime_error("Vertex shader compilation failed");
  } else {
    std::cout << "Shader " << file << " compiled successfully" << std::endl;
  }
}

GLuint sys::shaders::Shader::getHandle() const {
  return handle;
}
