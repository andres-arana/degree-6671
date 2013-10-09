#include "sys/input.h"
#include <GL/freeglut.h>
#include <stdexcept>

sys::Input* sys::Input::instance(0);

sys::Input::Input(const sys::init::Glut &glut, const sys::Params &params) {
  if (instance) {
    throw std::runtime_error("sys::Input can only be initialized once");
  }
  (void)glut;
  (void)params;
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

void sys::Input::disableKeyRepeatEvents() {
  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
}

void sys::Input::addCloseListener(sys::CloseListener &listener) {
  closeListeners.push_back(&listener);
}

void sys::Input::addReshapeListener(sys::ReshapeListener &listener) {
  reshapeListeners.push_back(&listener);
}

void sys::Input::addMouseListener(sys::MouseListener &listener) {
  mouseListeners.push_back(&listener);
}

void sys::Input::addMouseMotionListener(sys::MouseMotionListener &listener) {
  mouseMotionListeners.push_back(&listener);
}

void sys::Input::addKeyUpListener(sys::KeyUpListener &listener) {
  keyUpListeners.push_back(&listener);
}

void sys::Input::addKeyDownListener(sys::KeyDownListener &listener) {
  keyDownListeners.push_back(&listener);
}

void sys::Input::addIdleListener(sys::IdleListener &listener) {
  idleListeners.push_back(&listener);
}

void sys::Input::setRenderListener(sys::RenderListener &listener) {
  renderListener = &listener;
}

void sys::Input::onDisplay() {
  instance->renderListener->onRender();
}

void sys::Input::onClose() {
  sys::CloseEvent event;

  typedef std::vector<CloseListener *> Vector;
  Vector &listeners = instance->closeListeners;

  for (Vector::iterator it = listeners.begin(); it != listeners.end(); it++) {
    (*it)->onClose(event);
  }
}

void sys::Input::onReshape(int width, int height) {
  sys::ReshapeEvent event = { width, height };

  typedef std::vector<ReshapeListener *> Vector;
  Vector &listeners = instance->reshapeListeners;

  for (Vector::iterator it = listeners.begin(); it != listeners.end(); it++) {
    (*it)->onReshape(event);
  }
}

void sys::Input::onMouse(int button, int updown, int x, int y) {
  sys::MouseEvent event = { button, updown, x, y };

  typedef std::vector<MouseListener *> Vector;
  Vector &listeners = instance->mouseListeners;

  for (Vector::iterator it = listeners.begin(); it != listeners.end(); it++) {
    (*it)->onMouse(event);
  }
}

void sys::Input::onMouseMotion(int x, int y) {
  sys::MouseMotionEvent event = { x, y };

  typedef std::vector<MouseMotionListener *> Vector;
  Vector &listeners = instance->mouseMotionListeners;

  for (Vector::iterator it = listeners.begin(); it != listeners.end(); it++) {
    (*it)->onMouseMotion(event);
  }
}

void sys::Input::onKeyUp(unsigned char key, int x, int y) {
  sys::KeyUpEvent event = { key, x, y };

  typedef std::vector<KeyUpListener *> Vector;
  Vector &listeners = instance->keyUpListeners;

  for (Vector::iterator it = listeners.begin(); it != listeners.end(); it++) {
    (*it)->onKeyUp(event);
  }
}

void sys::Input::onKeyDown(unsigned char key, int x, int y) {
  sys::KeyDownEvent event = { key, x, y };

  typedef std::vector<KeyDownListener *> Vector;
  Vector &listeners = instance->keyDownListeners;

  for (Vector::iterator it = listeners.begin(); it != listeners.end(); it++) {
    (*it)->onKeyDown(event);
  }
}

void sys::Input::onIdle() {
  sys::IdleEvent event;

  typedef std::vector<IdleListener *> Vector;
  Vector &listeners = instance->idleListeners;

  for (Vector::iterator it = listeners.begin(); it != listeners.end(); it++) {
    (*it)->onIdle(event);
  }

  glutPostRedisplay();
}

