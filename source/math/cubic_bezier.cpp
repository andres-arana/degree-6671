#include "math/cubic_bezier.h"

using namespace math;

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

glm::vec3 cubic_bezier::apply(float x) const {
  return
    (-x * x * x + 3 * x * x - 3 * x + 1) * p0 +
    (3 * x * x * x - 6 * x * x + 3 * x) * p1 +
    (-3 * x * x * x + 3 * x * x) * p2 +
    (x * x * x) * p3;

};

glm::vec3 cubic_bezier::apply_derivate(float x) const {
  return
    (-3 * x * x + 6 * x - 3) * p0 +
    (9 * x * x - 12 * x + 3) * p1 +
    (-9 * x * x + 6 * x) * p2 +
    (3 * x * x) * p3;
};
