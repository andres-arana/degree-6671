#include "sys/init/info.h"
#include <GL/glew.h>
#include <string>
#include <iostream>

sys::init::Info::Info(const sys::Params &params) {
  (void) params;

  const GLubyte* rawGLVersion = glGetString(GL_VERSION);
  std::string glVersion((char*)rawGLVersion);
  std::cout << "Using OpenGL version " << glVersion.c_str() << std::endl;

  const GLubyte* rawShaderVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
  std::string shaderVersion((char*)rawShaderVersion);
  std::cout << "Using shading language version " << shaderVersion.c_str() << std::endl;
}
