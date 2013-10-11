#ifndef __APP_SCENE_SCENE_H_INCLUDED__
#define __APP_SCENE_SCENE_H_INCLUDED__

#include "sys/window.h"
#include "sys/input.h"
#include "app/geometries/register.h"
#include "app/shaders/register.h"
#include "app/scene/options.h"
#include "app/scene/floor.h"
#include "app/scene/light.h"
#include "app/scene/crab.h"
#include "app/scene/fpsCamera.h"
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
        Options options;
        FPSCamera fpsCamera;
        RotatingCamera rotatingCamera;
        Floor floor;
        Light light;
        Crab crab;

        Camera *currentCamera;

        float rotation;
    };
  };
};

#endif
