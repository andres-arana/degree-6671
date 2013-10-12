#ifndef __GEOM_REVOLUTION_SURFACE_H_INCLUDED__
#define __GEOM_REVOLUTION_SURFACE_H_INCLUDED__

#include "sys/shaderProgram.h"
#include "math/function.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace geom {
  class RevolutionSurface {
    public:
      RevolutionSurface(
          int angularSections,
          int longitudinalSections,
          const math::Function &f);

      RevolutionSurface(const RevolutionSurface &other) = delete;
      RevolutionSurface operator=(const RevolutionSurface &other) = delete;

      void render(
          const glm::mat4 &modelMatrix,
          const sys::ShaderProgram &shader) const;

    private:
      std::vector<GLfloat> vertexBuffer;
      std::vector<GLfloat> normalBuffer;
      std::vector<GLuint> indexBuffer;
  };
};

#endif
