#ifndef __SCENE_SCENE_H_INCLUDED__
#define __SCENE_SCENE_H_INCLUDED__

#include "sys/window.h"
#include "sys/input.h"
#include "geom/cache.h"
#include "shaders/cache.h"
#include "scene/floor.h"
#include "scene/light.h"
#include "scene/crab.h"
#include "scene/fpsCamera.h"
#include "scene/rotatingCamera.h"

namespace scene {
  class Scene {
    public:
      Scene(
          sys::Window &window,
          sys::Input &input);

      void render();

      void tick(float delta);

      void toggleCamera();

    private:
      geom::Cache geometries;
      shaders::Cache shaders;

      FPSCamera fpsCamera;
      RotatingCamera rotatingCamera;
      Floor floor;
      Light light;
      Crab crab;

      Camera *currentCamera;

      float rotation;
  };
};

#endif
