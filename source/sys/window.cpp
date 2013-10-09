#include "sys/window.h"
#include <GL/freeglut.h>
#include <iostream>

sys::Window::Window(const sys::init::Glut &glut, const sys::Params &params) {
  (void)glut;

  std::cout
    << "Creating application window "
    << params.title
    << " (" << params.width << "x" << params.height << ")"
    << std::endl;

  glutInitWindowSize(params.width, params.height);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  id = glutCreateWindow(params.title.c_str());
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

int sys::Window::getWidth() const {
  return glutGet(GLUT_WINDOW_WIDTH);
}

int sys::Window::getHeight() const {
  return glutGet(GLUT_WINDOW_HEIGHT);
}

void sys::Window::setCursorPosition(int x, int y) {
  glutWarpPointer(x, y);
}
