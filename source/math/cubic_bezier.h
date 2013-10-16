#ifndef __MATH_CUBIC_BEZIER_H_INCLUDE__
#define __MATH_CUBIC_BEZIER_H_INCLUDE__

#include "math/parametric_curve.h"

namespace math {
  class cubic_bezier : public parametric_curve {
    public:
      cubic_bezier(
          const glm::vec3 &p0,
          const glm::vec3 &p1,
          const glm::vec3 &p2,
          const glm::vec3 &p3);

      cubic_bezier(const cubic_bezier &other) = delete;
      cubic_bezier &operator=(const cubic_bezier &other) = delete;

      virtual glm::vec3 operator()(const float &x) const;

      virtual glm::vec3 derivative(const float &x) const;

    private:
      glm::vec3 p0;
      glm::vec3 p1;
      glm::vec3 p2;
      glm::vec3 p3;
  };
};

#endif
