#ifndef __MATH_CUBIC_BERNSTEIN_BASE_H_INCLUDED__
#define __MATH_CUBIC_BERNSTEIN_BASE_H_INCLUDED__

#include "math/real_function.h"

namespace math {
  class cubic_bernstein_base_0 : public real_function {
    public:
      cubic_bernstein_base_0() = default;

      cubic_bernstein_base_0(const cubic_bernstein_base_0 &other) = delete;
      cubic_bernstein_base_0& operator=(const cubic_bernstein_base_0 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

  class cubic_bernstein_base_1 : public real_function {
    public:
      cubic_bernstein_base_1() = default;

      cubic_bernstein_base_1(const cubic_bernstein_base_1 &other) = delete;
      cubic_bernstein_base_1& operator=(const cubic_bernstein_base_1 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

  class cubic_bernstein_base_2 : public real_function {
    public:
      cubic_bernstein_base_2() = default;

      cubic_bernstein_base_2(const cubic_bernstein_base_2 &other) = delete;
      cubic_bernstein_base_2& operator=(const cubic_bernstein_base_2 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

  class cubic_bernstein_base_3 : public real_function {
    public:
      cubic_bernstein_base_3() = default;

      cubic_bernstein_base_3(const cubic_bernstein_base_3 &other) = delete;
      cubic_bernstein_base_3& operator=(const cubic_bernstein_base_3 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };
};

#endif
