#include "math/cubic_bezier.h"
#include "math/cubic_bernstein_base.h"

using namespace math;

static cubic_bernstein_base_0 b0;
static cubic_bernstein_base_1 b1;
static cubic_bernstein_base_2 b2;
static cubic_bernstein_base_3 b3;

cubic_bezier::cubic_bezier(
    const glm::vec3 &p0,
    const glm::vec3 &p1,
    const glm::vec3 &p2,
    const glm::vec3 &p3) :
  p0(p0),
  p1(p1),
  p2(p2),
  p3(p3) {

  }

glm::vec3 cubic_bezier::operator()(const float &x) const {
  return
    b0(x) * p0 +
    b1(x) * p1 +
    b2(x) * p2 +
    b3(x) * p3;
};

glm::vec3 cubic_bezier::derivative(const float &x) const {
  return
    b0.derivative(x) * p0 +
    b1.derivative(x) * p1 +
    b2.derivative(x) * p2 +
    b3.derivative(x) * p3;
};
