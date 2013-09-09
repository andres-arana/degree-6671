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
  glutDisplayFunc(onDisplay);
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
