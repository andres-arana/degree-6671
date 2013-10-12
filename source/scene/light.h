#ifndef __SCENE_LIGHT_H_INCLUDED__
#define __SCENE_LIGHT_H_INCLUDED__

#include "shaders/cache.h"
#include <glm/glm.hpp> 

namespace scene {
  class Light {
    public:
      Light(const shaders::Cache &shaders);

      void use(
          const glm::mat4 &viewMatrix,
          const glm::mat4 &modelMatrix);

    private:
      const shaders::Cache &shaders;
  };
};

#endif
