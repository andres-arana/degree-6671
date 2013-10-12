#ifndef __SCENE_CRAB_H_INCLUDED__
#define __SCENE_CRAB_H_INCLUDED__

#include "geom/cache.h"
#include "shaders/cache.h"
#include <glm/glm.hpp> 

namespace scene {
  class Crab {
    public:
      Crab(
          const geom::Cache &geometries,
          const shaders::Cache &shaders);

      void render(
          const glm::mat4 &modelMatrix);

    private:
      const geom::Cache &geometries;
      const shaders::Cache &shaders;
  };
};

#endif
