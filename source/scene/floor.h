#ifndef __SCENE_FLOOR_H_INCLUDED__
#define __SCENE_FLOOR_H_INCLUDED__

#include "geom/cache.h"
#include "shaders/cache.h"
#include <glm/glm.hpp> 

namespace scene {
  class floor {
    public:
      floor(
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
