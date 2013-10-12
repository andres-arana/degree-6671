#ifndef __SCENE_CAMERA_H_INCLUDED__
#define __SCENE_CAMERA_H_INCLUDED__

#include "sys/events.h"
#include "sys/window.h"
#include "sys/input.h"
#include "shaders/cache.h"
#include <glm/glm.hpp> 

namespace scene {
  class camera :
    public sys::mouse_motion_listener,
    public sys::key_up_listener,
    public sys::key_down_listener {

      public:
        camera(
            sys::window &window,
            sys::input &input,
            const shaders::cache &shaders);

        virtual void on_mouse_motion(const sys::mouse_motion_event &event);
        virtual void on_key_up(const sys::key_up_event &event);
        virtual void on_key_down(const sys::key_down_event &event);
        virtual glm::mat4 use();

        virtual void do_mouse_move(int delta_x, int delta_y) = 0;
        virtual void do_key_up(unsigned char key) = 0;
        virtual void do_key_down(unsigned char key) = 0;
        virtual void tick(float delta) = 0;
        virtual glm::mat4 get_view_matrix() = 0;

        virtual ~camera() {};
      protected:
        sys::window &window;
        const shaders::cache &shaders;
    };
};

#endif
