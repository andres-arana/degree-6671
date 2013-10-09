#include "sys/init/glut.h"
#include <GL/freeglut.h>

sys::init::Glut::Glut(const sys::Params &params) {
  glutInit(params.argc, params.argv);
}

void sys::init::Glut::mainLoop() {
  glutMainLoop();
}

void sys::init::Glut::leaveMainLoop() {
  glutLeaveMainLoop();
}

unsigned int sys::init::Glut::getTime() const {
  return glutGet(GLUT_ELAPSED_TIME);
}

