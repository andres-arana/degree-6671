#include "sys/input.h"
#include <GL/freeglut.h>
#include <stdexcept>

using namespace sys;

input* input::instance(0);

input::input(const init::glut &glut) {
  if (instance) {
    throw std::runtime_error("sys::Input can only be initialized once");
  }
  (void)glut;
  instance = this;
  glutDisplayFunc(on_display);
  glutReshapeFunc(on_reshape);
  glutMouseFunc(on_mouse);
  glutPassiveMotionFunc(on_mouse_motion);
  glutCloseFunc(on_close);
  glutKeyboardFunc(on_key_down);
  glutKeyboardUpFunc(on_key_up);
  glutIdleFunc(on_idle);
}

void input::disable_key_repeat_events() {
  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
}

void input::add_close_listener(close_listener &listener) {
  close_listeners.push_back(&listener);
}

void input::add_reshape_listener(reshape_listener &listener) {
  reshape_listeners.push_back(&listener);
}

void input::add_mouse_listener(mouse_listener &listener) {
  mouse_listeners.push_back(&listener);
}

void input::add_mouse_motion_listener(mouse_motion_listener &listener) {
  mouse_motion_listeners.push_back(&listener);
}

void input::add_key_up_listener(key_up_listener &listener) {
  key_up_listeners.push_back(&listener);
}

void input::add_key_down_listener(key_down_listener &listener) {
  key_down_listeners.push_back(&listener);
}

void input::add_idle_listener(idle_listener &listener) {
  idle_listeners.push_back(&listener);
}

void input::set_render_listener(render_listener &listener) {
  current_render_listener = &listener;
}

void input::on_display() {
  instance->current_render_listener->on_render();
}

void input::on_close() {
  close_event event;

  for (auto &it : instance->close_listeners) {
    it->on_close(event);
  }
}

void input::on_reshape(int width, int height) {
  reshape_event event = { width, height };

  for (auto &it : instance->reshape_listeners) {
    it->on_reshape(event);
  }
}

void input::on_mouse(int button, int updown, int x, int y) {
  mouse_event event = { button, updown, x, y };

  for (auto &it : instance->mouse_listeners) {
    it->on_mouse(event);
  }
}

void input::on_mouse_motion(int x, int y) {
  mouse_motion_event event = { x, y };

  for (auto &it : instance->mouse_motion_listeners) {
    it->on_mouse_motion(event);
  }
}

void input::on_key_up(unsigned char key, int x, int y) {
  key_up_event event = { key, x, y };

  for (auto &it : instance->key_up_listeners) {
    it->on_key_up(event);
  }
}

void input::on_key_down(unsigned char key, int x, int y) {
  key_down_event event = { key, x, y };

  for (auto &it : instance->key_down_listeners) {
    it->on_key_down(event);
  }
}

void input::on_idle() {
  idle_event event;

  for (auto &it : instance->idle_listeners) {
    it->on_idle(event);
  }

  glutPostRedisplay();
}

