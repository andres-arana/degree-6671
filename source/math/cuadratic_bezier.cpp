#include "math/cuadratic_bezier.h"
#include "math/cuadratic_bernstein_base.h"

using namespace math;

static cuadratic_bernstein_base_0 b0;
static cuadratic_bernstein_base_1 b1;
static cuadratic_bernstein_base_2 b2;

cuadratic_bezier::cuadratic_bezier(
    const glm::vec3 &p0,
    const glm::vec3 &p1,
    const glm::vec3 &p2) :
  p0(p0),
  p1(p1),
  p2(p2) {

  }

glm::vec3 cuadratic_bezier::operator()(const float &x) const {
  return
    b0(x) * p0 +
    b1(x) * p1 +
    b2(x) * p2;
};

glm::vec3 cuadratic_bezier::derivative(const float &x) const {
  return
    b0.derivative(x) * p0 +
    b1.derivative(x) * p1 +
    b2.derivative(x) * p2;
};
