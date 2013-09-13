#include "sys/context.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

sys::Context::Context(Application &application) : 
  application(application),
  window(*this),
  input(*this) {

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

sys::Input &sys::Context::getInput() {
  return input;
}

void sys::Context::runEventLoop() {
  glutMainLoop();
}

