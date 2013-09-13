#ifndef __SYS_INPUT_DISPATCHER_H_INCLUDED__
#define __SYS_INPUT_DISPATCHER_H_INCLUDED__

#include "sys/input/events.h"

namespace sys {
  namespace input {

    class Dispatcher {
      public:
        virtual ~Dispatcher() {};

        virtual void onClose(const CloseEvent &event) {};

        virtual void onReshape(const ReshapeEvent &event) {};

        virtual void onMouse(const MouseEvent &event) {};

        virtual void onMouseWheel(const MouseWheelEvent &event) {};

        virtual void onMouseMotion(const MouseMotionEvent &event) {};

        virtual void onSpecialKeyUp(const SpecialKeyUpEvent &event) {};

        virtual void onKeyUp(const KeyUpEvent &event) {};

        virtual void onSpecialKeyDown(const SpecialKeyDownEvent &event) {};

        virtual void onKeyDown(const KeyDownEvent &event) {};

        virtual void onIdle(const IdleEvent &event) {};
    };

  };
};

#endif

