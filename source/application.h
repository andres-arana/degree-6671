#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

#include "sys/window.h"
#include "sys/input.h"
#include "sys/system.h"
#include "scene/world.h"

class application :
  public sys::render_listener,
  public sys::reshape_listener,
  public sys::key_up_listener,
  public sys::idle_listener {

    public:
      application(
          sys::system<application> &system,
          sys::window &window, sys::input &input);

      application(const application &other) = delete;
      application &operator=(const application &other) = delete;

      virtual void on_render();
      virtual void on_reshape(const sys::reshape_event &event);
      virtual void on_key_up(const sys::key_up_event &event);
      virtual void on_idle(const sys::idle_event &event);

    private:
      sys::system<application> &system;
      sys::window &window;
      sys::input &input;

      scene::world world;

      unsigned int previous_time;
  };

#endif
