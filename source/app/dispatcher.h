#ifndef __APP_DISPATCHER_H_INCLUDED__
#define __APP_DISPATCHER_H_INCLUDED__

#include "sys/application.h"

namespace app {

  class Dispatcher : public sys::input::Dispatcher {
    public:
      virtual void onKeyUp(const sys::input::KeyUpEvent &event);

      virtual void onMouseMotion(const sys::input::MouseMotionEvent &event);
  };

};

#endif
