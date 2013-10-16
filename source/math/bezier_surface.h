#ifndef __MATH_BEZIER_SURFACE_H_INCLUDED__
#define __MATH_BEZIER_SURFACE_H_INCLUDED__

#include "math/parametric_surface.h"

namespace math {
  class bezier_surface : public parametric_surface {
    public:
      bezier_surface(
          const glm::vec3 &p00, const glm::vec3 &p01,
          const glm::vec3 &p02, const glm::vec3 &p03,

          const glm::vec3 &p10, const glm::vec3 &p11,
          const glm::vec3 &p12, const glm::vec3 &p13,

          const glm::vec3 &p20, const glm::vec3 &p21,
          const glm::vec3 &p22, const glm::vec3 &p23,

          const glm::vec3 &p30, const glm::vec3 &p31,
          const glm::vec3 &p32, const glm::vec3 &p33);

      bezier_surface(const bezier_surface &other) = delete;
      bezier_surface& operator=(const bezier_surface &other) = delete;

      virtual glm::vec3 operator()(const glm::vec2 &value) const;

      virtual glm::vec3 derivative_u(const glm::vec2 &value) const;

      virtual glm::vec3 derivative_v(const glm::vec2 &value) const;

    private:
          const glm::vec3 p00;
          const glm::vec3 p01;
          const glm::vec3 p02;
          const glm::vec3 p03;

          const glm::vec3 p10;
          const glm::vec3 p11;
          const glm::vec3 p12;
          const glm::vec3 p13;

          const glm::vec3 p20;
          const glm::vec3 p21;
          const glm::vec3 p22;
          const glm::vec3 p23;

          const glm::vec3 p30;
          const glm::vec3 p31;
          const glm::vec3 p32;
          const glm::vec3 p33;
  };
};

#endif
