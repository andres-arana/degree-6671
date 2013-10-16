#ifndef __GEOM_REVOLUTION_SURFACE_H_INCLUDED__
#define __GEOM_REVOLUTION_SURFACE_H_INCLUDED__

#include "sys/shader_program.h"
#include "math/parametric_curve.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace geom {
  class revolution_surface {
    public:
      revolution_surface(
          int angular_sections,
          int longitudinal_sections,
          const math::parametric_curve &f);

      revolution_surface(const revolution_surface &other) = delete;
      revolution_surface operator=(const revolution_surface &other) = delete;

      void render(
          const glm::mat4 &model_matrix,
          const sys::shader_program &shader) const;

    private:
      std::vector<GLfloat> vertex_buffer;
      std::vector<GLfloat> normal_buffer;
      std::vector<GLuint> index_buffer;
  };
};

#endif
