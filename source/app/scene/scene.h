#ifndef __APP_SCENE_SCENE_H_INCLUDED__
#define __APP_SCENE_SCENE_H_INCLUDED__

#include "sys/window.h"
#include "sys/input.h"
#include "app/geometries/register.h"
#include "app/shaders/register.h"
#include "app/scene/floor.h"
#include "app/scene/arm.h"
#include "app/scene/FPSCamera.h"
#include "app/scene/rotatingCamera.h"

namespace app {
  namespace scene {
    class Scene {
      public:
        Scene(
            sys::Window &window,
            sys::Input &input,
            const app::geometries::Register &geometries, 
            const app::shaders::Register &shaders);

        void render();

        void tick(float delta);

        void toggleCamera();

      private:
        const app::geometries::Register &geometries;
        const app::shaders::Register &shaders;

        FPSCamera fpsCamera;
        RotatingCamera rotatingCamera;
        Floor floor;
        Arm arm;

        Camera *currentCamera;
    };
  };
};

#endif
