#include "math/cuadratic_bezier.h"

using namespace math;

cuadratic_bezier::cuadratic_bezier(
    const glm::vec3 &p0,
    const glm::vec3 &p1,
    const glm::vec3 &p2) :
  p0(p0),
  p1(p1),
  p2(p2) {

  }

glm::vec3 cuadratic_bezier::apply(float x) const {
  return
    (x * x - 2 * x + 1) * p0 +
    (-2 * x * x + 2 * x) * p1 +
    (x * x) * p2;

};

glm::vec3 cuadratic_bezier::apply_derivate(float x) const {
  return
    (2 * x - 2) * p0 +
    (-4 * x + 2) * p1 +
    (2 * x) * p2;
};
