#ifndef __MATH_CUADRATIC_BEZIER_H_INCLUDE__
#define __MATH_CUADRATIC_BEZIER_H_INCLUDE__

#include "math/function.h"

namespace math {
  class cuadratic_bezier : public math::function {
    public:
      cuadratic_bezier(
          const glm::vec3 &p0,
          const glm::vec3 &p1,
          const glm::vec3 &p2);

      cuadratic_bezier(const cuadratic_bezier &other) = delete;
      cuadratic_bezier &operator=(const cuadratic_bezier &other) = delete;

      virtual glm::vec3 apply(float x) const;

      virtual glm::vec3 apply_derivate(float x) const;

    private:
      glm::vec3 p0;
      glm::vec3 p1;
      glm::vec3 p2;
  };
};

#endif
