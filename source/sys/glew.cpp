#include "sys/glew.h"
#include <iostream>
#include <stdexcept>
#include <GL/glew.h>

sys::Glew::Glew() {
  std::cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;
  GLenum result = glewInit();
  if (GLEW_OK != result) {
    std::cout << "Failed to initialize GLEW! " << glewGetErrorString(result) << std::endl;
    throw std::runtime_error("Failed to initialize GLEW");
  } else {
  }
}

/* void fwk::Window::initializeGLEW() { */

/*   const GLubyte* sVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB); */
/*   std::string version((char*)sVersion); */
/*   std::cout << "Using shading language version " << version.c_str() << std::endl; */
/* } */

