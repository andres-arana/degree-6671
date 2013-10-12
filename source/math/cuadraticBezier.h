#ifndef __MATH_CUADRATIC_BEZIER_H_INCLUDE__
#define __MATH_CUADRATIC_BEZIER_H_INCLUDE__

#include "geom/revolutionSurface.h"
#include "math/function.h"

namespace math {
  class CuadraticBezier : public math::Function {
    public:
      CuadraticBezier(
          const glm::vec3 &p0,
          const glm::vec3 &p1,
          const glm::vec3 &p2);

      CuadraticBezier(const CuadraticBezier &other) = delete;
      CuadraticBezier &operator=(const CuadraticBezier &other) = delete;

      virtual glm::vec3 apply(float x) const;

      virtual glm::vec3 applyDerivate(float x) const;

    private:
      glm::vec3 p0;
      glm::vec3 p1;
      glm::vec3 p2;
  };
};

#endif
