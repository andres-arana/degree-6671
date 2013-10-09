#include "app/scene/camera.h"

app::scene::Camera::Camera(sys::Window &window, sys::Input &input) :
  window(window) {
    input.addMouseMotionListener(*this);
    input.addKeyUpListener(*this);
    input.addKeyDownListener(*this);
  }

void app::scene::Camera::onMouseMotion(const sys::MouseMotionEvent &event) {
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
    doMouseMove(deltaX, deltaY);
    window.setCursorPosition(middleX, middleY);
  }
}

void app::scene::Camera::onKeyUp(const sys::KeyUpEvent &event) {
  doKeyUp(event.key);
}

void app::scene::Camera::onKeyDown(const sys::KeyDownEvent &event) {
  doKeyDown(event.key);
}
