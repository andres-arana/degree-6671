#ifndef __APP_SCENE_ARM_H_INCLUDED__
#define __APP_SCENE_ARM_H_INCLUDED__

#include "app/geometries/register.h"
#include "app/shaders/diffuseShader.h"
#include "app/scene/armSection.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class Arm {
      public:
        Arm(const app::geometries::Register &geometries, 
            const app::shaders::DiffuseShader &shader);

        void render(const glm::mat4 &modelMatrix);

      private:
        const app::geometries::Register &geometries;
        const app::shaders::DiffuseShader &shader;

        ArmSection armSection;
    };
  };
};

#endif
