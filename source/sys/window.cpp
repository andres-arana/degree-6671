#include "sys/window.h"
#include <GL/freeglut.h>
#include <iostream>

using namespace sys;

Window::Window(const init::Glut &glut, const Params &params) {
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

void Window::toggleFullScreen() {
  glutFullScreenToggle();
}

void Window::hideCursor() {
  glutSetCursor(GLUT_CURSOR_NONE);
}

void Window::showCursor() {
  glutSetCursor(GLUT_CURSOR_INHERIT);
}

void Window::swapBuffers() {
  glutSwapBuffers();
}

float Window::getAspectRatio() const {
  float width = getWidth();
  float height = getHeight();

  return width / height;
}

int Window::getWidth() const {
  return glutGet(GLUT_WINDOW_WIDTH);
}

int Window::getHeight() const {
  return glutGet(GLUT_WINDOW_HEIGHT);
}

void Window::setCursorPosition(int x, int y) {
  glutWarpPointer(x, y);
}
