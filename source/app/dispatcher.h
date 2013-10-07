#ifndef __APP_DISPATCHER_H_INCLUDED__
#define __APP_DISPATCHER_H_INCLUDED__

#include "sys/application.h"

namespace app {
  class Application;

  class Dispatcher : public sys::input::Dispatcher {
    public:
      Dispatcher(Application &application);

      virtual void onKeyUp(const sys::input::KeyUpEvent &event);

      virtual void onKeyDown(const sys::input::KeyDownEvent &event);

      virtual void onMouseMotion(const sys::input::MouseMotionEvent &event);

      virtual void onIdle(const sys::input::IdleEvent &event);
    private:
      Application &application;

      int previousMousePositionX;
      int previousMousePositionY;
      unsigned int previousTime;
  };

};

#endif
