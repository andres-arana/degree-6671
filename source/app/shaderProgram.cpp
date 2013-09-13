#include "app/shaderProgram.h"
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include <stdexcept>

app::ShaderProgram::ShaderProgram(
    const app::Shader &vertexShader,
    const app::Shader &fragmentShader) {

  handle = glCreateProgram();
  if (0 == handle) 
    throw std::runtime_error("Unable to create shader program handle");

  glAttachShader(handle, vertexShader.getHandle());
  glAttachShader(handle, fragmentShader.getHandle());
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

void app::ShaderProgram::use() const {
  glUseProgram(handle);
}
