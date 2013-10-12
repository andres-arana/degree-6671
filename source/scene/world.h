#ifndef __SCENE_WORLD_H_INCLUDED__
#define __SCENE_WORLD_H_INCLUDED__

#include "sys/window.h"
#include "sys/input.h"
#include "geom/cache.h"
#include "shaders/cache.h"
#include "scene/floor.h"
#include "scene/light.h"
#include "scene/crab.h"
#include "scene/fps_camera.h"
#include "scene/rotating_camera.h"

namespace scene {
  class world {
    public:
      world(
          sys::window &window,
          sys::input &input);

      void render();

      void tick(float delta);

      void toggle_camera();

    private:
      geom::cache geometries;
      shaders::cache shaders;

      scene::fps_camera fps_camera;
      scene::rotating_camera rotating_camera;
      scene::floor floor;
      scene::light light;
      scene::crab crab;

      scene::camera *current_camera;

      float rotation;
  };
};

#endif
