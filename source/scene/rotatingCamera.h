#ifndef __SCENE_ROTATION_CAMERA_H_INCLUDED__
#define __SCENE_ROTATION_CAMERA_H_INCLUDED__

#include "scene/camera.h"

namespace scene {
  class RotatingCamera : public Camera {
    public:
      RotatingCamera(
          sys::Window &window,
          sys::Input &input,
          const glm::vec3 &center,
          float distance,
          const shaders::Cache &shaders);

      virtual void doMouseMove(int deltaX, int deltaY);
      virtual void doKeyUp(unsigned char key);
      virtual void doKeyDown(unsigned char key);
      virtual void tick(float delta);

      glm::mat4 getViewMatrix();

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
