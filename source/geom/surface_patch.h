#ifndef __GEOM_SURFACE_PATCH_H_INCLUDED__
#define __GEOM_SURFACE_PATCH_H_INCLUDED__

#include "sys/shader_program.h"
#include "math/parametric_surface.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace geom {
  class surface_patch {
    public:
      surface_patch(
          int u_sections,
          int v_sections,
          const math::parametric_surface &f);

      surface_patch(const surface_patch &other) = delete;
      surface_patch operator=(const surface_patch &other) = delete;

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
