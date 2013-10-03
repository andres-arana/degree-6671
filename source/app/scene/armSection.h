#ifndef __APP_SCENE_ARM_SECTION_H_INCLUDED__
#define __APP_SCENE_ARM_SECTION_H_INCLUDED__

#include "app/geometries/register.h"
#include "app/shaders/register.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class ArmSection {
      public:
        ArmSection(const app::geometries::Register &geometries, 
            const app::shaders::Register &shaders);

        void render(const glm::mat4 &modelMatrix);

      private:
        const app::geometries::Register &geometries;
        const app::shaders::DiffuseShader &shader;
    };
  };
};

#endif
