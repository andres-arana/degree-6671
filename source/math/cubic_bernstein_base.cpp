#include "math/cubic_bernstein_base.h"

using namespace math;

float cubic_bernstein_base_0::operator()(const float &x) const {
  return (-x * x * x + 3 * x * x - 3 * x + 1);
}

float cubic_bernstein_base_1::operator()(const float &x) const {
  return (3 * x * x * x - 6 * x * x + 3 * x);
}

float cubic_bernstein_base_2::operator()(const float &x) const {
  return (-3 * x * x * x + 3 * x * x);
}

float cubic_bernstein_base_3::operator()(const float &x) const {
  return (x * x * x);
}

float cubic_bernstein_base_0::derivative(const float &x) const {
  return (-3 * x * x + 6 * x - 3);
}

float cubic_bernstein_base_1::derivative(const float &x) const {
  return (9 * x * x - 12 * x + 3);
}

float cubic_bernstein_base_2::derivative(const float &x) const {
  return (-9 * x * x + 6 * x);
}

float cubic_bernstein_base_3::derivative(const float &x) const {
  return (3 * x * x);
}
