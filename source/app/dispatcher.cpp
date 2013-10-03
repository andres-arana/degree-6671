#include "app/dispatcher.h"
#include "sys/context.h"

void app::Dispatcher::onKeyUp(const sys::input::KeyUpEvent &event) {
  if (event.key == 'f') {
    event.context.getWindow().toggleFullScreen();
  } else if (event.key == 0x1b) {
    event.context.exitEventLoop();
  }
}

