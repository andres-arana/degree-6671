#include "math/cuadratic_bernstein_base.h"

using namespace math;

float cuadratic_bernstein_base_0::operator()(const float &x) const {
  return (x * x - 2 * x + 1);
}

float cuadratic_bernstein_base_1::operator()(const float &x) const {
  return (-2 * x * x + 2 * x);
}

float cuadratic_bernstein_base_2::operator()(const float &x) const {
  return (x * x);
}

float cuadratic_bernstein_base_0::derivative(const float &x) const {
  return (2 * x - 2);
}

float cuadratic_bernstein_base_1::derivative(const float &x) const {
  return (-4 * x + 2);
}

float cuadratic_bernstein_base_2::derivative(const float &x) const {
  return (2 * x);
}

