#include "math/cuadratic_bspline_surface.h"
#include "math/cuadratic_bspline_basis.h"

using namespace math;

static cuadratic_bspline_basis_0 b0;
static cuadratic_bspline_basis_1 b1;
static cuadratic_bspline_basis_2 b2;
/* static std::vector<real_function &> b; */

cuadratic_bspline_surface::cuadratic_bspline_surface(const std::vector<std::vector<glm::vec3>> &control_points) :
  control_points(control_points) {

  }

glm::vec3 cuadratic_bspline_surface::operator()(const glm::vec2 &value) const {


}

glm::vec3 cuadratic_bspline_surface::derivative_u(const glm::vec2 &value) const {

}

glm::vec3 cuadratic_bspline_surface::derivative_v(const glm::vec2 &value) const {

}
