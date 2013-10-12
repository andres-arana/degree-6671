#include "sys/init/glut.h"
#include <GL/freeglut.h>

using namespace sys;
using namespace sys::init;

glut::glut(const params &params) {
  glutInit(params.argc, params.argv);
}

void glut::main_loop() {
  glutMainLoop();
}

void glut::leave_main_loop() {
  glutLeaveMainLoop();
}

unsigned int glut::get_time() const {
  return glutGet(GLUT_ELAPSED_TIME);
}

