#ifndef __MATH_CUBIC_BEZIER_H_INCLUDE__
#define __MATH_CUBIC_BEZIER_H_INCLUDE__

#include "math/function.h"

namespace math {
  class cubic_bezier : public math::function {
    public:
      cubic_bezier(
          const glm::vec3 &p0,
          const glm::vec3 &p1,
          const glm::vec3 &p2,
          const glm::vec3 &p3);

      cubic_bezier(const cubic_bezier &other) = delete;
      cubic_bezier &operator=(const cubic_bezier &other) = delete;

      virtual glm::vec3 apply(float x) const;

      virtual glm::vec3 apply_derivate(float x) const;

    private:
      glm::vec3 p0;
      glm::vec3 p1;
      glm::vec3 p2;
      glm::vec3 p3;
  };
};

#endif
