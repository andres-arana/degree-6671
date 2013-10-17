#ifndef __SCENE_CRAB_H_INCLUDED__
#define __SCENE_CRAB_H_INCLUDED__

#include "geom/cache.h"
#include "shaders/cache.h"
#include "scene/crab_leg.h"
#include "scene/crab_eye.h"
#include "scene/crab_arm.h"
#include "math/cyclic_interval.h"
#include <glm/glm.hpp> 

namespace scene {
  class crab {
    public:
      crab(
          const geom::cache &geometries,
          const shaders::cache &shaders);

      void render(
          const glm::mat4 &model_matrix);

      void tick(float delta);

    private:
      math::cyclic_interval time;
      float distance;
      
      const geom::cache &geometries;
      const shaders::cache &shaders;

      scene::crab_leg leg;
      scene::crab_eye eye;
      scene::crab_arm arm;
  };
};

#endif
