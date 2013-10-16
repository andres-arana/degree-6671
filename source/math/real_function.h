#ifndef __MATH_REAL_FUNCTION_H_INCLUDED__
#define __MATH_REAL_FUNCTION_H_INCLUDED__

#include "math/function.h"

namespace math {
  class real_function : public function<float, float> {
    public:
      virtual float derivative(const float &x) const = 0;
  };
};
#endif
