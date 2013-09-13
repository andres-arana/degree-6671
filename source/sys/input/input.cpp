#include "sys/input/input.h"
#include "sys/input/events.h"
#include "sys/context.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

sys::input::Input* sys::input::Input::instance(0);

sys::input::Input::Input(sys::Context &context) :
  context(context) {
    instance = this;
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onReshape);
    glutMouseFunc(onMouse);
    glutMotionFunc(onMouseMotion);
    glutMouseWheelFunc(onMouseWheel);
    glutCloseFunc(onClose);
    glutKeyboardFunc(onKeyDown);
    glutSpecialFunc(onSpecialKeyDown);
    glutKeyboardUpFunc(onKeyUp);
    glutSpecialUpFunc(onSpecialKeyUp);
    glutIdleFunc(onIdle);
  }

sys::Application &sys::input::Input::getApplication() {
  return context.getApplication();
}

void sys::input::Input::onDisplay() {
  instance->getApplication().getRenderer().render();
}

void sys::input::Input::onClose() {
  sys::input::CloseEvent event = { instance->context };
  instance->getApplication().getDispatcher().onClose(event);
}

void sys::input::Input::onReshape(int width, int height) {
  sys::input::ReshapeEvent event = { instance->context, width, height };
  instance->getApplication().getDispatcher().onReshape(event);
}

void sys::input::Input::onMouse(int button, int updown, int x, int y) {
  sys::input::MouseEvent event = { instance->context, button, updown, x, y };
  instance->getApplication().getDispatcher().onMouse(event);
}

void sys::input::Input::onMouseWheel(int wheelNumber, int direction, int x, int y) {
  sys::input::MouseWheelEvent event = { instance->context, wheelNumber, direction, x, y };
  instance->getApplication().getDispatcher().onMouseWheel(event);
}

void sys::input::Input::onMouseMotion(int x, int y) {
  sys::input::MouseMotionEvent event = { instance->context, x, y };
  instance->getApplication().getDispatcher().onMouseMotion(event);
}

void sys::input::Input::onSpecialKeyUp(int key, int x, int y) {
  sys::input::SpecialKeyUpEvent event = { instance->context, key, x, y };
  instance->getApplication().getDispatcher().onSpecialKeyUp(event);
}

void sys::input::Input::onKeyUp(unsigned char key, int x, int y) {
  sys::input::KeyUpEvent event = { instance->context, key, x, y };
  instance->getApplication().getDispatcher().onKeyUp(event);
}

void sys::input::Input::onSpecialKeyDown(int key, int x, int y) {
  sys::input::SpecialKeyDownEvent event = { instance->context, key, x, y };
  instance->getApplication().getDispatcher().onSpecialKeyDown(event);
}

void sys::input::Input::onKeyDown(unsigned char key, int x, int y) {
  sys::input::KeyDownEvent event = { instance->context, key, x, y };
  instance->getApplication().getDispatcher().onKeyDown(event);
}

void sys::input::Input::onIdle() {
  sys::input::IdleEvent event = { instance->context };
  instance->getApplication().getDispatcher().onIdle(event);
}

