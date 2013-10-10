#ifndef __APP_GEOMETRIES_REVOLUTION_SURFACE_H_INCLUDED__
#define __APP_GEOMETRIES_REVOLUTION_SURFACE_H_INCLUDED__

#include "sys/shaders/shaderProgram.h"
#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <vector>

namespace app {
  namespace geometries {
    class Function {
      public:
        virtual glm::vec3 apply(float x) const = 0;
        virtual glm::vec3 applyDerivate(float x) const = 0;

        virtual ~Function() {};
    };

    class RevolutionSurface {
      public:
        RevolutionSurface(int angularSections, int longitudinalSections, const Function &f);

        void render(
            const glm::mat4 &modelMatrix,
            const sys::shaders::ShaderProgram &shader) const;

      private:
        std::vector<GLfloat> vertexBuffer;
        std::vector<GLfloat> normalBuffer;
        std::vector<GLuint> indexBuffer;
    };
  };
};
#endif
