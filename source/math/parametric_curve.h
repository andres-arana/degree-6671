#ifndef __MATH_PARAMETRIC_CURVE_H_INCLUDED__
#define __MATH_PARAMETRIC_CURVE_H_INCLUDED__

#include <glm/glm.hpp>
#include "math/function.h"

namespace math {
  class parametric_curve : public function<float, glm::vec3> {
    public:
      virtual glm::vec3 derivative(const float &x) const = 0;
  };
};

#endif

