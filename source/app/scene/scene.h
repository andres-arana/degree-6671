#ifndef __APP_SCENE_SCENE_H_INCLUDED__
#define __APP_SCENE_SCENE_H_INCLUDED__

#include "app/geometries/register.h"
#include "app/shaders/register.h"
#include "app/scene/floor.h"
#include "app/scene/arm.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class Scene {
      public:
        Scene(const app::geometries::Register &geometries, 
            const app::shaders::Register &shaders);

        void render(const glm::mat4 &modelMatrix);

      private:
        Floor floor;
        Arm arm;
    };
  };
};

#endif
