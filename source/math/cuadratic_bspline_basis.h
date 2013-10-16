#ifndef __MATH_CUADRATIC_BSPLINE_BASIS_H_INCLUDED__
#define __MATH_CUADRATIC_BSPLINE_BASIS_H_INCLUDED__

#include "math/real_function.h"

namespace math {
  class cuadratic_bspline_basis_0 : public real_function {
    public:
      cuadratic_bspline_basis_0() = default;

      cuadratic_bspline_basis_0(const cuadratic_bspline_basis_0 &other) = delete;
      cuadratic_bspline_basis_0& operator=(const cuadratic_bspline_basis_0 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

  class cuadratic_bspline_basis_1 : public real_function {
    public:
      cuadratic_bspline_basis_1() = default;

      cuadratic_bspline_basis_1(const cuadratic_bspline_basis_1 &other) = delete;
      cuadratic_bspline_basis_1& operator=(const cuadratic_bspline_basis_1 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };

  class cuadratic_bspline_basis_2 : public real_function {
    public:
      cuadratic_bspline_basis_2() = default;

      cuadratic_bspline_basis_2(const cuadratic_bspline_basis_2 &other) = delete;
      cuadratic_bspline_basis_2& operator=(const cuadratic_bspline_basis_2 &other) = delete;

      virtual float operator()(const float &x) const;

      virtual float derivative(const float &x) const;
  };
};

#endif
