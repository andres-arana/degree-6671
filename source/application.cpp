#include "application.h"

using namespace sys;

Application::Application(System<Application> &system, Window &window, Input &input) :
  system(system),
  window(window),
  input(input),
  scene(window, input),
  previousTime(0) {
    window.hideCursor();
    input.disableKeyRepeatEvents();

    input.setRenderListener(*this);
    input.addReshapeListener(*this);
    input.addKeyUpListener(*this);
    input.addIdleListener(*this);
  }

void Application::onRender() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  scene.render();

  window.swapBuffers();
}

void Application::onReshape(const ReshapeEvent &event) {
  glViewport(0, 0, (GLsizei) event.width, (GLsizei) event.height);
}

void Application::onKeyUp(const KeyUpEvent &event) {
  if (event.key == 'f') {
    window.toggleFullScreen();
  } else if (event.key == 'c') {
    scene.toggleCamera();
  } else if (event.key == 0x1b) {
    system.exitEventLoop();
  }
}

void Application::onIdle(const IdleEvent &event) {
  (void)event;

  if (!previousTime) {
    previousTime = system.getTime();
    return;
  }

  auto currentTime = system.getTime();
  auto delta = (currentTime - previousTime) / 1000.0f;

  scene.tick(delta);

  previousTime = currentTime;
}

