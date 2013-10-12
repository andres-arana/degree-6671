#include "sys/init/info.h"
#include <GL/glew.h>
#include <string>
#include <iostream>

using namespace sys;
using namespace sys::init;

Info::Info() {
  auto rawGLVersion = glGetString(GL_VERSION);
  std::string glVersion((char*)rawGLVersion);
  std::cout << "Using OpenGL version " << glVersion.c_str() << std::endl;

  auto rawShaderVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
  std::string shaderVersion((char*)rawShaderVersion);
  std::cout << "Using shading language version " << shaderVersion.c_str() << std::endl;
}
