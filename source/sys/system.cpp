#include "sys/system.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

sys::System::System(int argc, char** argv) : context(0) {
  std::cout << std::endl << "Booting application" << std::endl;

  glutInit(&argc, argv);
}

sys::Context &sys::System::createContext(sys::Application &application) {
  if (!context) {
    context = new sys::Context(application);
  }

  return *context;
}

sys::System::~System() {
  if (context) {
    delete context;
  }
}

