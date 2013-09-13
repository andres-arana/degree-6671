#include "app/dispatcher.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

void app::Dispatcher::onKeyUp(unsigned char key, int x, int y) {
  if (key == 'f') {
    glutFullScreenToggle();
  } else if (key == 0x1b) {
    glutLeaveMainLoop();
  }
}
