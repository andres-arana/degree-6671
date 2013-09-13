#ifndef __SYS_INPUT_EVENTS_H_INCLUDED__
#define __SYS_INPUT_EVENTS_H_INCLUDED__

namespace sys {
  class Context;

  namespace input {
    struct CloseEvent {
      Context &context;
    };

    struct ReshapeEvent {
      Context &context;
      int width;
      int height;
    };

    struct MouseEvent {
      Context &context;
      int button;
      int updown;
      int x;
      int y;
    };

    struct MouseWheelEvent {
      Context &context;
      int wheelNumber;
      int direction;
      int x;
      int y;
    };

    struct MouseMotionEvent {
      Context &context;
      int x;
      int y;
    };

    struct SpecialKeyUpEvent {
      Context &context;
      int key;
      int x;
      int y;
    };

    struct KeyUpEvent {
      Context &context;
      unsigned char key;
      int x;
      int y;
    };

    struct SpecialKeyDownEvent {
      Context &context;
      int key;
      int x;
      int y;
    };

    struct KeyDownEvent {
      Context &context;
      unsigned char key;
      int x;
      int y;
    };

    struct IdleEvent {
      Context &context;
    };
  };
};

#endif
