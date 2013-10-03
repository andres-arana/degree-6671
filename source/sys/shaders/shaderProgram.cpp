#include "sys/shaders/shaderProgram.h"
#include <vector>
#include <iostream>
#include <stdexcept>

sys::shaders::ShaderProgram::ShaderProgram(
    sys::shaders::VertexShader *vertexShader,
    sys::shaders::FragmentShader *fragmentShader) :
  vertexShader(vertexShader),
  fragmentShader(fragmentShader)
{

  handle = glCreateProgram();
  if (0 == handle) 
    throw std::runtime_error("Unable to create shader program handle");

  glAttachShader(handle, vertexShader->getHandle());
  glAttachShader(handle, fragmentShader->getHandle());
  glLinkProgram(handle);

  GLint status;
  glGetProgramiv(handle, GL_LINK_STATUS, &status);
  if (GL_FALSE == status) {
    std::cout << "Shader program link failed" << std::endl;

    GLint logLength;
    glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
      std::vector<char> log(logLength);
      glGetProgramInfoLog(handle, logLength, 0, &log[0]);
      std::cout << &log[0] << std::endl;
    }

    throw std::runtime_error("Unable to link shader program");
  } else {
    std::cout << "Shader program linked successfully" << std::endl;
  }
}

void sys::shaders::ShaderProgram::use() const {
  glUseProgram(handle);
}

sys::shaders::ShaderParam sys::shaders::ShaderProgram::getUniformParam(const char* name) const {
  GLuint paramHandle = glGetUniformLocation(handle, name);
  return sys::shaders::ShaderParam(paramHandle);
}

sys::shaders::ShaderProgram::~ShaderProgram() {

}
