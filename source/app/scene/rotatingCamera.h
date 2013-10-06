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
            const glm::vec3 &center,
            float distance,
            const app::shaders::Register &shaders);

        virtual void onMouseMove(int deltaX, int deltaY);

        virtual void onKeyUp(unsigned char key);

        void use();

      private:
        const app::shaders::Register &shaders;
        const glm::vec3 center;
        float distance;
        float rho;
        float theta;
    };
  };
};

#endif
