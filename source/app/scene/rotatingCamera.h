#ifndef __APP_SCENE_ROTATION_CAMERA_H_INCLUDED__
#define __APP_SCENE_ROTATION_CAMERA_H_INCLUDED__

#include "app/shaders/register.h"
#include "app/scene/camera.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class RotatingCamera : public Camera {
      public:
        RotatingCamera(
            sys::Window &window,
            sys::Input &input,
            const glm::vec3 &center,
            float distance,
            const app::shaders::Register &shaders);

        virtual void doMouseMove(int deltaX, int deltaY);
        virtual void doKeyUp(unsigned char key);
        virtual void doKeyDown(unsigned char key);
        virtual void tick(float delta);
        virtual void use();

      private:
        const app::shaders::Register &shaders;
        const glm::vec3 center;
        float distance;
        float rho;
        float theta;

        bool forwards;
        bool backwards;
    };
  };
};

#endif
