#include "app/dispatcher.h"
#include "app/application.h"
#include "sys/context.h"

app::Dispatcher::Dispatcher(app::Application &application) :
  application(application) {

  }

void app::Dispatcher::onKeyUp(const sys::input::KeyUpEvent &event) {
  if (event.key == 'f') {
    event.context.getWindow().toggleFullScreen();
  } else if (event.key == 'c') {
    application.toggleCamera();
  } else if (event.key == 0x1b) {
    event.context.exitEventLoop();
  }

  application.getCamera().onKeyUp(event.key);
}

void app::Dispatcher::onKeyDown(const sys::input::KeyDownEvent &event) {
  application.getCamera().onKeyDown(event.key);
}

void app::Dispatcher::onMouseMotion(const sys::input::MouseMotionEvent &event) {
  sys::Window &window = event.context.getWindow();

  int middleX = window.getWidth() / 2;
  int middleY = window.getHeight() / 2;

  int deltaX = event.x - middleX;
  int deltaY = event.y - middleY;

  if (deltaX < 3 && deltaX > -3) {
    deltaX = 0;
  }
   
  if (deltaY < 3 && deltaY > -3) {
    deltaY = 0;
  }

  if (deltaX || deltaY) {
    application.getCamera().onMouseMove(deltaX, deltaY);
    window.setCursorPosition(middleX, middleY);
  }

}

void app::Dispatcher::onIdle(const sys::input::IdleEvent &event) {
  if (!previousTime) {
    previousTime = event.context.getInput().getTime();
    return;
  }

  unsigned int currentTime = event.context.getInput().getTime();

  float delta = (float)(currentTime - previousTime) / 1000.0f;

  application.tick(delta);

  previousTime = currentTime;
}

