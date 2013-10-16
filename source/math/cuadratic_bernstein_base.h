#ifndef __MATH_CUADRATIC_BERNSTEIN_BASE_H_INCLUDED__
#define __MATH_CUADRATIC_BERNSTEIN_BASE_H_INCLUDED__

#include "math/real_function.h"

namespace math {
  class cuadratic_bernstein_base_0 : public real_function {
    public:
      cuadratic_bernstein_base_0() = default;

      cuadratic_bernstein_base_0(const cuadratic_bernstein_base_0 &other) = delete;
      cuadratic_bernstein_base_0& operator=(const cuadratic_bernstein_base_0 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

  class cuadratic_bernstein_base_1 : public real_function {
    public:
      cuadratic_bernstein_base_1() = default;

      cuadratic_bernstein_base_1(const cuadratic_bernstein_base_1 &other) = delete;
      cuadratic_bernstein_base_1& operator=(const cuadratic_bernstein_base_1 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

  class cuadratic_bernstein_base_2 : public real_function {
    public:
      cuadratic_bernstein_base_2() = default;

      cuadratic_bernstein_base_2(const cuadratic_bernstein_base_2 &other) = delete;
      cuadratic_bernstein_base_2& operator=(const cuadratic_bernstein_base_2 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

};

#endif
