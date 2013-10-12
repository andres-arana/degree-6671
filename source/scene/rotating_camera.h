#ifndef __SCENE_ROTATION_CAMERA_H_INCLUDED__
#define __SCENE_ROTATION_CAMERA_H_INCLUDED__

#include "scene/camera.h"

namespace scene {
  class rotating_camera : public camera {
    public:
      rotating_camera(
          sys::window &window,
          sys::input &input,
          const glm::vec3 &center,
          float distance,
          const shaders::cache &shaders);

      virtual void do_mouse_move(int delta_x, int delta_y);
      virtual void do_key_up(unsigned char key);
      virtual void do_key_down(unsigned char key);
      virtual void tick(float delta);

      glm::mat4 get_view_matrix();

    private:
      const glm::vec3 center;
      float distance;
      float rho;
      float theta;

      bool forwards;
      bool backwards;
  };
};

#endif
