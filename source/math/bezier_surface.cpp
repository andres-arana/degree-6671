#include "math/bezier_surface.h"
#include "math/cubic_bernstein_base.h"

using namespace math;

static cubic_bernstein_base_0 b0;
static cubic_bernstein_base_1 b1;
static cubic_bernstein_base_2 b2;
static cubic_bernstein_base_3 b3;

bezier_surface::bezier_surface(
    const glm::vec3 &p00, const glm::vec3 &p01,
    const glm::vec3 &p02, const glm::vec3 &p03,

    const glm::vec3 &p10, const glm::vec3 &p11,
    const glm::vec3 &p12, const glm::vec3 &p13,

    const glm::vec3 &p20, const glm::vec3 &p21,
    const glm::vec3 &p22, const glm::vec3 &p23,

    const glm::vec3 &p30, const glm::vec3 &p31,
    const glm::vec3 &p32, const glm::vec3 &p33) :
  p00(p00), p01(p01), p02(p02), p03(p03),
  p10(p10), p11(p11), p12(p12), p13(p13),
  p20(p20), p21(p21), p22(p22), p23(p23),
  p30(p30), p31(p31), p32(p32), p33(p33) {

  }

glm::vec3 bezier_surface::operator()(const glm::vec2 &value) const {
  return
    b0(value.x) * b0(value.y) * p00 +
    b0(value.x) * b1(value.y) * p01 +
    b0(value.x) * b2(value.y) * p02 +
    b0(value.x) * b3(value.y) * p03 +
    b1(value.x) * b0(value.y) * p10 +
    b1(value.x) * b1(value.y) * p11 +
    b1(value.x) * b2(value.y) * p12 +
    b1(value.x) * b3(value.y) * p13 +
    b2(value.x) * b0(value.y) * p20 +
    b2(value.x) * b1(value.y) * p21 +
    b2(value.x) * b2(value.y) * p22 +
    b2(value.x) * b3(value.y) * p23 +
    b3(value.x) * b0(value.y) * p30 +
    b3(value.x) * b1(value.y) * p31 +
    b3(value.x) * b2(value.y) * p32 +
    b3(value.x) * b3(value.y) * p33;
}

glm::vec3 bezier_surface::derivative_u(const glm::vec2 &value) const {
  return
    b0.derivative(value.x) * b0(value.y) * p00 +
    b0.derivative(value.x) * b1(value.y) * p01 +
    b0.derivative(value.x) * b2(value.y) * p02 +
    b0.derivative(value.x) * b3(value.y) * p03 +
    b1.derivative(value.x) * b0(value.y) * p10 +
    b1.derivative(value.x) * b1(value.y) * p11 +
    b1.derivative(value.x) * b2(value.y) * p12 +
    b1.derivative(value.x) * b3(value.y) * p13 +
    b2.derivative(value.x) * b0(value.y) * p20 +
    b2.derivative(value.x) * b1(value.y) * p21 +
    b2.derivative(value.x) * b2(value.y) * p22 +
    b2.derivative(value.x) * b3(value.y) * p23 +
    b3.derivative(value.x) * b0(value.y) * p30 +
    b3.derivative(value.x) * b1(value.y) * p31 +
    b3.derivative(value.x) * b2(value.y) * p32 +
    b3.derivative(value.x) * b3(value.y) * p33;
}

glm::vec3 bezier_surface::derivative_v(const glm::vec2 &value) const {
  return
    b0(value.x) * b0.derivative(value.y) * p00 +
    b0(value.x) * b1.derivative(value.y) * p01 +
    b0(value.x) * b2.derivative(value.y) * p02 +
    b0(value.x) * b3.derivative(value.y) * p03 +
    b1(value.x) * b0.derivative(value.y) * p10 +
    b1(value.x) * b1.derivative(value.y) * p11 +
    b1(value.x) * b2.derivative(value.y) * p12 +
    b1(value.x) * b3.derivative(value.y) * p13 +
    b2(value.x) * b0.derivative(value.y) * p20 +
    b2(value.x) * b1.derivative(value.y) * p21 +
    b2(value.x) * b2.derivative(value.y) * p22 +
    b2(value.x) * b3.derivative(value.y) * p23 +
    b3(value.x) * b0.derivative(value.y) * p30 +
    b3(value.x) * b1.derivative(value.y) * p31 +
    b3(value.x) * b2.derivative(value.y) * p32 +
    b3(value.x) * b3.derivative(value.y) * p33;
}
