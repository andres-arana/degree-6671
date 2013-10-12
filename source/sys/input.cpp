#include "sys/input.h"
#include <GL/freeglut.h>
#include <stdexcept>

using namespace sys;

Input* Input::instance(0);

Input::Input(const init::Glut &glut) {
  if (instance) {
    throw std::runtime_error("sys::Input can only be initialized once");
  }
  (void)glut;
  instance = this;
  glutDisplayFunc(onDisplay);
  glutReshapeFunc(onReshape);
  glutMouseFunc(onMouse);
  glutPassiveMotionFunc(onMouseMotion);
  glutCloseFunc(onClose);
  glutKeyboardFunc(onKeyDown);
  glutKeyboardUpFunc(onKeyUp);
  glutIdleFunc(onIdle);
}

void Input::disableKeyRepeatEvents() {
  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
}

void Input::addCloseListener(CloseListener &listener) {
  closeListeners.push_back(&listener);
}

void Input::addReshapeListener(ReshapeListener &listener) {
  reshapeListeners.push_back(&listener);
}

void Input::addMouseListener(MouseListener &listener) {
  mouseListeners.push_back(&listener);
}

void Input::addMouseMotionListener(MouseMotionListener &listener) {
  mouseMotionListeners.push_back(&listener);
}

void Input::addKeyUpListener(KeyUpListener &listener) {
  keyUpListeners.push_back(&listener);
}

void Input::addKeyDownListener(KeyDownListener &listener) {
  keyDownListeners.push_back(&listener);
}

void Input::addIdleListener(IdleListener &listener) {
  idleListeners.push_back(&listener);
}

void Input::setRenderListener(RenderListener &listener) {
  renderListener = &listener;
}

void Input::onDisplay() {
  instance->renderListener->onRender();
}

void Input::onClose() {
  CloseEvent event;

  for (auto &it : instance->closeListeners) {
    it->onClose(event);
  }
}

void Input::onReshape(int width, int height) {
  ReshapeEvent event = { width, height };

  for (auto &it : instance->reshapeListeners) {
    it->onReshape(event);
  }
}

void Input::onMouse(int button, int updown, int x, int y) {
  MouseEvent event = { button, updown, x, y };

  for (auto &it : instance->mouseListeners) {
    it->onMouse(event);
  }
}

void Input::onMouseMotion(int x, int y) {
  MouseMotionEvent event = { x, y };

  for (auto &it : instance->mouseMotionListeners) {
    it->onMouseMotion(event);
  }
}

void Input::onKeyUp(unsigned char key, int x, int y) {
  KeyUpEvent event = { key, x, y };

  for (auto &it : instance->keyUpListeners) {
    it->onKeyUp(event);
  }
}

void Input::onKeyDown(unsigned char key, int x, int y) {
  KeyDownEvent event = { key, x, y };

  for (auto &it : instance->keyDownListeners) {
    it->onKeyDown(event);
  }
}

void Input::onIdle() {
  IdleEvent event;

  for (auto &it : instance->idleListeners) {
    it->onIdle(event);
  }

  glutPostRedisplay();
}

