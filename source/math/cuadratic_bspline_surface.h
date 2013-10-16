#ifndef __MATH_CUADRATIC_BSPLINE_SURFACE_H_INCLUDED__
#define __MATH_CUADRATIC_BSPLINE_SURFACE_H_INCLUDED__

#include "math/parametric_surface.h"
#include <vector>

namespace math {
  class cuadratic_bspline_surface : public parametric_surface {
    public:
      cuadratic_bspline_surface(const std::vector<std::vector<glm::vec3>> &control_points);

      cuadratic_bspline_surface(const cuadratic_bspline_surface &other) = delete;
      cuadratic_bspline_surface& operator=(const cuadratic_bspline_surface &other) = delete;

      virtual glm::vec3 operator()(const glm::vec2 &value) const;

      virtual glm::vec3 derivative_u(const glm::vec2 &value) const;

      virtual glm::vec3 derivative_v(const glm::vec2 &value) const;

    private:
      std::vector<std::vector<glm::vec3>> control_points;
  };
};

#endif
