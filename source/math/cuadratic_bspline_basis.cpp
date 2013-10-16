#include "math/cuadratic_bspline_basis.h"

using namespace math;

float cuadratic_bspline_basis_0::operator()(const float &x) const {
  return 0.5f * (1 - x) * (1 - x);
}

float cuadratic_bspline_basis_1::operator()(const float &x) const {
  return - x * x + x + 0.5f;
}

float cuadratic_bspline_basis_2::operator()(const float &x) const {
  return x * x * 0.5f;
}

float cuadratic_bspline_basis_0::derivative(const float &x) const {
  return x - 1;
}

float cuadratic_bspline_basis_1::derivative(const float &x) const {
  return -2 * x + 1;
}

float cuadratic_bspline_basis_2::derivative(const float &x) const {
  return x;
}
