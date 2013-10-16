#ifndef __MATH_PARAMETRIC_SURFACE_H_INCLUDED__
#define __MATH_PARAMETRIC_SURFACE_H_INCLUDED__

#include <glm/glm.hpp>
#include "math/function.h"

namespace math {
  class parametric_surface : public function<glm::vec2, glm::vec3> {
    public:
      virtual glm::vec3 derivative_u(const glm::vec2 &value) const = 0;

      virtual glm::vec3 derivative_v(const glm::vec2 &value) const = 0;

  };
};

#endif
