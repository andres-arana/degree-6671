#ifndef __SCENE_CRAB_LEG_H_INCLUDED__
#define __SCENE_CRAB_LEG_H_INCLUDED__

#include "geom/cache.h"
#include "shaders/cache.h"
#include <glm/glm.hpp> 

namespace scene {
  class crab_leg {
    public:
      crab_leg(
          const geom::cache &geometries,
          const shaders::cache &shaders);

      void render(
          const glm::mat4 &model_matrix);

    private:
      const geom::cache &geometries;
      const shaders::cache &shaders;
  };
};

#endif
