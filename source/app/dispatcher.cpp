#include "app/dispatcher.h"
#include "sys/context.h"
#include <iostream>

void app::Dispatcher::onKeyUp(const sys::input::KeyUpEvent &event) {
  if (event.key == 'f') {
    event.context.getWindow().toggleFullScreen();
  } else if (event.key == 0x1b) {
    event.context.exitEventLoop();
  }
}

void app::Dispatcher::onMouseMotion(const sys::input::MouseMotionEvent &event) {
  sys::Window &window = event.context.getWindow();

  std::cout 
    << "Mouse moved (" << event.x << ", " << event.y << ")"
    << " Window size is " << window.getWidth() << "x" << window.getHeight()
    << std::endl;
}

