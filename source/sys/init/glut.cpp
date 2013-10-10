#include "sys/init/glut.h"
#include <GL/freeglut.h>

using namespace sys;
using namespace sys::init;

Glut::Glut(const Params &params) {
  glutInit(params.argc, params.argv);
}

void Glut::mainLoop() {
  glutMainLoop();
}

void Glut::leaveMainLoop() {
  glutLeaveMainLoop();
}

unsigned int Glut::getTime() const {
  return glutGet(GLUT_ELAPSED_TIME);
}

