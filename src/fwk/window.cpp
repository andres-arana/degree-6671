#include "window.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

fwk::Window::Window(Dispatcher &dispatcher, const char* title, int width, int height) : dispatcher(dispatcher) {
  std::cout << "Initializing window " << title << " (" << width << "x" << height << ")" << std::endl;
  glutInitWindowSize(width, height);
  glutInitWindowPosition(0, 0);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  this->id = glutCreateWindow(title);

  this->initializeGLEW();
}

bool fwk::Window::is(int id) const {
  return this->id == id;
}

fwk::Dispatcher &fwk::Window::dispatch() {
  return dispatcher;
}


void fwk::Window::initializeGLEW() {
  std::cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;
  GLenum result = glewInit();
  if (GLEW_OK != result) {
    std::cout << "Failed to initialize GLEW! " << glewGetErrorString(result) << std::endl;
  } else {
    std::cout << "GLEW initialized" << std::endl;
  }

  int major, minor, revision;
  const GLubyte* sVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
  std::string version((char*)sVersion);
  std::cout << "Using shading language version " << version.c_str() << std::endl;
}

