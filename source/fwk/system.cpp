#include "system.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

fwk::System::Windows fwk::System::windows;

fwk::System::System(int argc, char** argv) {
  glutInit(&argc, argv);
}

fwk::System::~System() {
  for (Windows::iterator it = windows.begin(); it != windows.end(); it++) {
    delete *it;
  }
}

fwk::Window &fwk::System::createWindow(Dispatcher &dispatcher, const char *title, int width, int height) {
  fwk::Window *window = new fwk::Window(dispatcher, title, width, height);
  windows.push_back(window);
  return *window;
}

void fwk::System::runEventLoop() {
  for (Windows::iterator it = windows.begin(); it != windows.end(); it++) {
    (*it)->dispatch().onInit();
  }
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

  glutMainLoop();
}

fwk::System::Windows::iterator fwk::System::lookupCurrentWindow() {
  int id = glutGetWindow();
  for (Windows::iterator it = windows.begin(); it != windows.end(); it++) {
    if ((*it)->is(id)) {
      return it;
    }
  }

  return windows.end();
}

void fwk::System::onDisplay() {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onDisplay();
  }
}

void fwk::System::onClose() {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onClose();
  }
}

void fwk::System::onReshape(int width, int height) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onReshape(width, height);
  }
}

void fwk::System::onMouse(int button, int updown, int x, int y) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onMouse(button, updown, x, y);
  }
}

void fwk::System::onMouseWheel(int whellNumber, int direction, int x, int y) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onMouseWheel(whellNumber, direction, x, y);
  }
}

void fwk::System::onMouseMotion(int x, int y) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onMouseMotion(x, y);
  }
}

void fwk::System::onSpecialKeyUp(int key, int x, int y) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onSpecialKeyUp(key, x, y);
  }
}

void fwk::System::onKeyUp(unsigned char key, int x, int y) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onKeyUp(key, x, y);
  }
}

void fwk::System::onSpecialKeyDown(int key, int x, int y) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onSpecialKeyDown(key, x, y);
  }
}

void fwk::System::onKeyDown(unsigned char key, int x, int y) {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onKeyDown(key, x, y);
  }
}

void fwk::System::onIdle() {
  Windows::iterator it = lookupCurrentWindow();
  if (it != windows.end()) {
    (*it)->dispatch().onIdle();
  }
}
