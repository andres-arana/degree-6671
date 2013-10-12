#ifndef __SCENE_FPS_CAMERA_H_INCLUDED__
#define __SCENE_FPS_CAMERA_H_INCLUDED__

#include "scene/camera.h"

namespace scene {
  class fps_camera : public camera {
    public:
      fps_camera(
          sys::window &window,
          sys::input &input,
          const glm::vec3 &position,
          const shaders::cache &shaders);

      virtual void do_mouse_move(int delta_x, int delta_y);

      virtual void do_key_up(unsigned char key);

      virtual void do_key_down(unsigned char key);

      virtual void tick(float delta);

      virtual glm::mat4 get_view_matrix();

    private:
      glm::vec3 position;
      float rho;
      float theta;

      bool forwards;
      bool backwards;
      bool left;
      bool right;
      bool up;
      bool down;
  };
};

#endif
