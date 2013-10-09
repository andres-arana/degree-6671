#ifndef __SYS_EVENTS_H_INCLUDED__
#define __SYS_EVENTS_H_INCLUDED__

namespace sys {
  struct CloseEvent {

  };

  class CloseListener {
    public:
      virtual void onClose(const CloseEvent &event) = 0;
      virtual ~CloseListener() {};
  };

  struct ReshapeEvent {
    int width;
    int height;
  };

  class ReshapeListener {
    public:
      virtual void onReshape(const ReshapeEvent &event) = 0;
      virtual ~ReshapeListener() {};
  };

  struct MouseEvent {
    int button;
    int updown;
    int x;
    int y;
  };

  class MouseListener {
    public:
      virtual void onMouse(const MouseEvent &event) = 0;
      virtual ~MouseListener() {};
  };

  struct MouseMotionEvent {
    int x;
    int y;
  };

  class MouseMotionListener {
    public:
      virtual void onMouseMotion(const MouseMotionEvent &event) = 0;
      virtual ~MouseMotionListener() {};
  };

  struct KeyUpEvent {
    unsigned char key;
    int x;
    int y;
  };

  class KeyUpListener {
    public:
      virtual void onKeyUp(const KeyUpEvent &event) = 0;
      virtual ~KeyUpListener() {};
  };

  struct KeyDownEvent {
    unsigned char key;
    int x;
    int y;
  };

  class KeyDownListener {
    public:
      virtual void onKeyDown(const KeyDownEvent &event) = 0;
      virtual ~KeyDownListener() {};
  };

  struct IdleEvent {

  };

  class IdleListener {
    public:
      virtual void onIdle(const IdleEvent &event) = 0;
      virtual ~IdleListener() {};
  };

  class RenderListener {
    public:
      virtual void onRender() = 0;
      virtual ~RenderListener() {};
  };
};

#endif
