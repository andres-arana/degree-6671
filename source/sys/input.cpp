#include "sys/input.h"
#include "sys/context.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

sys::Input* sys::Input::instance(0);

sys::Input::Input(sys::Context &context) :
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

sys::Application &sys::Input::getApplication() {
  return context.getApplication();
}

void sys::Input::onDisplay() {
  instance->getApplication().getRenderer().render();
}

void sys::Input::onClose() {
  instance->getApplication().getDispatcher().onClose();
}

void sys::Input::onReshape(int width, int height) {
  instance->getApplication().getDispatcher().onReshape(width, height);
}

void sys::Input::onMouse(int button, int updown, int x, int y) {
  instance->getApplication().getDispatcher().onMouse(button, updown, x, y);
}

void sys::Input::onMouseWheel(int whellNumber, int direction, int x, int y) {
  instance->getApplication().getDispatcher().onMouseWheel(whellNumber, direction, x, y);
}

void sys::Input::onMouseMotion(int x, int y) {
  instance->getApplication().getDispatcher().onMouseMotion(x, y);
}

void sys::Input::onSpecialKeyUp(int key, int x, int y) {
  instance->getApplication().getDispatcher().onSpecialKeyUp(key, x, y);
}

void sys::Input::onKeyUp(unsigned char key, int x, int y) {
  instance->getApplication().getDispatcher().onKeyUp(key, x, y);
}

void sys::Input::onSpecialKeyDown(int key, int x, int y) {
  instance->getApplication().getDispatcher().onSpecialKeyDown(key, x, y);
}

void sys::Input::onKeyDown(unsigned char key, int x, int y) {
  instance->getApplication().getDispatcher().onKeyDown(key, x, y);
}

void sys::Input::onIdle() {
  instance->getApplication().getDispatcher().onIdle();
}

