#include "sys/window.h"
#include <GL/freeglut.h>
#include <iostream>

using namespace sys;

window::window(const init::glut &glut, const params &params) {
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

void window::toggle_full_screen() {
  glutFullScreenToggle();
}

void window::hide_cursor() {
  glutSetCursor(GLUT_CURSOR_NONE);
}

void window::show_cursor() {
  glutSetCursor(GLUT_CURSOR_INHERIT);
}

void window::swap_buffers() {
  glutSwapBuffers();
}

float window::get_aspect_ratio() const {
  float width = get_width();
  float height = get_height();

  return width / height;
}

int window::get_width() const {
  return glutGet(GLUT_WINDOW_WIDTH);
}

int window::get_height() const {
  return glutGet(GLUT_WINDOW_HEIGHT);
}

void window::set_cursor_position(int x, int y) {
  glutWarpPointer(x, y);
}
