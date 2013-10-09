#include "sys/init/glew.h"
#include <iostream>
#include <stdexcept>
#include <GL/glew.h>

sys::init::Glew::Glew(const sys::Window &window, const sys::Params &params) {
  (void)window;
  (void)params;

  std::cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;
  GLenum result = glewInit();
  if (GLEW_OK != result) {
    std::cout << "Failed to initialize GLEW! " << glewGetErrorString(result) << std::endl;
    throw std::runtime_error("Failed to initialize GLEW");
  }
}

