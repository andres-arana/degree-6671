#ifndef __SYS_EVENTS_H_INCLUDED__
#define __SYS_EVENTS_H_INCLUDED__

namespace sys {
  struct close_event {

  };

  class close_listener {
    public:
      virtual void on_close(const close_event &event) = 0;
      virtual ~close_listener() {};
  };

  struct reshape_event {
    int width;
    int height;
  };

  class reshape_listener {
    public:
      virtual void on_reshape(const reshape_event &event) = 0;
      virtual ~reshape_listener() {};
  };

  struct mouse_event {
    int button;
    int updown;
    int x;
    int y;
  };

  class mouse_listener {
    public:
      virtual void on_mouse(const mouse_event &event) = 0;
      virtual ~mouse_listener() {};
  };

  struct mouse_motion_event {
    int x;
    int y;
  };

  class mouse_motion_listener {
    public:
      virtual void on_mouse_motion(const mouse_motion_event &event) = 0;
      virtual ~mouse_motion_listener() {};
  };

  struct key_up_event {
    unsigned char key;
    int x;
    int y;
  };

  class key_up_listener {
    public:
      virtual void on_key_up(const key_up_event &event) = 0;
      virtual ~key_up_listener() {};
  };

  struct key_down_event {
    unsigned char key;
    int x;
    int y;
  };

  class key_down_listener {
    public:
      virtual void on_key_down(const key_down_event &event) = 0;
      virtual ~key_down_listener() {};
  };

  struct idle_event {

  };

  class idle_listener {
    public:
      virtual void on_idle(const idle_event &event) = 0;
      virtual ~idle_listener() {};
  };

  class render_listener {
    public:
      virtual void on_render() = 0;
      virtual ~render_listener() {};
  };
};

#endif
