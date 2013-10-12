#ifndef __SCENE_LIGHT_H_INCLUDED__
#define __SCENE_LIGHT_H_INCLUDED__

#include "shaders/cache.h"
#include <glm/glm.hpp> 

namespace scene {
  class light {
    public:
      light(const shaders::cache &shaders);

      void use(
          const glm::mat4 &view_matrix,
          const glm::mat4 &model_matrix);

    private:
      const shaders::cache &shaders;
  };
};

#endif
