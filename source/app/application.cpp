#include "app/application.h"

app::Application::Application(sys::System<app::Application> &system, sys::Window &window, sys::Input &input) :
  system(system),
  window(window),
  input(input),
  scene(window, input, geometries, shaders) {
    window.hideCursor();
    input.disableKeyRepeatEvents();

    input.setRenderListener(*this);
    input.addReshapeListener(*this);
    input.addKeyUpListener(*this);
    input.addIdleListener(*this);
  }

void app::Application::onRender() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  scene.render();

  window.swapBuffers();
}

void app::Application::onReshape(const sys::ReshapeEvent &event) {
  glViewport(0, 0, (GLsizei) event.width, (GLsizei) event.height);
}

void app::Application::onKeyUp(const sys::KeyUpEvent &event) {
  if (event.key == 'f') {
    window.toggleFullScreen();
  } else if (event.key == 'c') {
    scene.toggleCamera();
  } else if (event.key == 0x1b) {
    system.exitEventLoop();
  }
}

void app::Application::onIdle(const sys::IdleEvent &event) {
  (void)event;

  if (!previousTime) {
    previousTime = system.getTime();
    return;
  }

  unsigned int currentTime = system.getTime();

  float delta = (currentTime - previousTime) / 1000.0f;

  scene.tick(delta);

  previousTime = currentTime;
}

