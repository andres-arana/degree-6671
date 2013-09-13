#include "sys/system.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

sys::System::System(int argc, char** argv) : context(0) {
  glutInit(&argc, argv);
  glutSetOption(
      GLUT_ACTION_ON_WINDOW_CLOSE,
      GLUT_ACTION_GLUTMAINLOOP_RETURNS);
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

