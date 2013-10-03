#include "sys/context.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

sys::Context::Context(Application &application) : 
  application(application),
  window(*this),
  input(*this) {
    const GLubyte* rawGLVersion = glGetString(GL_VERSION);
    std::string glVersion((char*)rawGLVersion);
    std::cout << "Using OpenGL version " << glVersion.c_str() << std::endl;

    const GLubyte* rawShaderVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
    std::string shaderVersion((char*)rawShaderVersion);
    std::cout << "Using shading language version " << shaderVersion.c_str() << std::endl;
  }

sys::Application &sys::Context::getApplication() {
  return application;
}

sys::Window &sys::Context::getWindow() {
  return window;
}

sys::Glew &sys::Context::getGlew() {
  return glew;
}

sys::input::Input &sys::Context::getInput() {
  return input;
}

void sys::Context::runEventLoop() {
  glutMainLoop();
}

void sys::Context::exitEventLoop() {
  glutLeaveMainLoop();
}

