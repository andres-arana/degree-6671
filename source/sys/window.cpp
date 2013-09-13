#include "sys/window.h"
#include "sys/context.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

sys::Window::Window(Context &context) {
  sys::Application &application = context.getApplication();

  glutInitWindowSize(application.getWidth(), application.getHeight());
  glutInitWindowPosition(application.getPositionX(), application.getPositionY());
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  id = glutCreateWindow(application.getTitle());
}

bool sys::Window::isIdentifiedBy(unsigned int windowId) const {
  return windowId == id;
}

void sys::Window::toggleFullScreen() {
  glutFullScreenToggle();
}
