#ifndef __SYS_INPUT_H_INCLUDED__
#define __SYS_INPUT_H_INCLUDED__

#include "sys/events.h"
#include "sys/init/glut.h"
#include <vector>


namespace sys {
  class input {
    public:
      input(const sys::init::glut &glut);

      input(const input &other) = delete;
      input &operator=(const input &other) = delete;

      void disable_key_repeat_events();

      void add_close_listener(close_listener &listener);
      void add_reshape_listener(reshape_listener &listener);
      void add_mouse_listener(mouse_listener &listener);
      void add_mouse_motion_listener(mouse_motion_listener &listener);
      void add_key_up_listener(key_up_listener &listener);
      void add_key_down_listener(key_down_listener &listener);
      void add_idle_listener(idle_listener &listener);
      void set_render_listener(render_listener &listener);

    private:

      render_listener *current_render_listener;
      std::vector<close_listener *> close_listeners;
      std::vector<reshape_listener *> reshape_listeners;
      std::vector<mouse_listener *> mouse_listeners;
      std::vector<mouse_motion_listener *> mouse_motion_listeners;
      std::vector<key_up_listener *> key_up_listeners;
      std::vector<key_down_listener *> key_down_listeners;
      std::vector<idle_listener *> idle_listeners;

      static input *instance;

      static void on_display();
      static void on_close();
      static void on_reshape(int width, int height);
      static void on_mouse(int button, int updown, int x, int y);
      static void on_mouse_motion(int x, int y);
      static void on_key_up(unsigned char key, int x, int y);
      static void on_key_down(unsigned char key, int x, int y);
      static void on_idle();
  };
};

#endif
