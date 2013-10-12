#include "sys/init/info.h"
#include <GL/glew.h>
#include <string>
#include <iostream>

using namespace sys;
using namespace sys::init;

info::info() {
  auto raw_gl_version = glGetString(GL_VERSION);
  std::string gl_version((char*)raw_gl_version);
  std::cout << "Using OpenGL version " << gl_version.c_str() << std::endl;

  auto raw_shader_version = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
  std::string shader_version((char*)raw_shader_version);
  std::cout << "Using shading language version " << shader_version.c_str() << std::endl;
}
