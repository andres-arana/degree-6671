#include "sys/window.h"
#include "sys/context.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

sys::Window::Window(Context &context) {
  sys::Application &application = context.getApplication();

  std::cout 
    << "Creating application window " 
    << application.getTitle() 
    << " (" << application.getWidth() << "x" << application.getHeight() << ")" 
    << std::endl;

  glutInitWindowSize(application.getWidth(), application.getHeight());
  glutInitWindowPosition(application.getPositionX(), application.getPositionY());
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  id = glutCreateWindow(application.getTitle());
  application.configureWindow(*this);
}

bool sys::Window::isIdentifiedBy(unsigned int windowId) const {
  return windowId == id;
}

void sys::Window::toggleFullScreen() {
  glutFullScreenToggle();
}

void sys::Window::hideCursor() {
  glutSetCursor(GLUT_CURSOR_NONE);
}

void sys::Window::showCursor() {
  glutSetCursor(GLUT_CURSOR_INHERIT);
}

void sys::Window::swapBuffers() {
  glutSwapBuffers();
}

float sys::Window::getAspectRatio() const {
  float width = getWidth();
  float height = getHeight();

  return width / height;
}

unsigned int sys::Window::getWidth() const {
  return glutGet(GLUT_WINDOW_WIDTH);
}

unsigned int sys::Window::getHeight() const {
  return glutGet(GLUT_WINDOW_HEIGHT);
}

void sys::Window::setCursorPosition(unsigned int x, unsigned int y) {
  glutWarpPointer(x, y);
}
