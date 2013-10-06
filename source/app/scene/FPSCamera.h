#ifndef __APP_SCENE_FPS_CAMERA_H_INCLUDED__
#define __APP_SCENE_FPS_CAMERA_H_INCLUDED__

#include "app/shaders/register.h"
#include "app/scene/camera.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class FPSCamera : public Camera {
      public:
        FPSCamera(
            const glm::vec3 &position,
            const app::shaders::Register &shaders);

        virtual void onMouseMove(int deltaX, int deltaY);

        virtual void onKeyUp(unsigned char key);

        void use();

      private:
        const app::shaders::Register &shaders;
        glm::vec3 position;
        float rho;
        float theta;
    };
  };
};

#endif
