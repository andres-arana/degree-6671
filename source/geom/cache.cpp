#include "geom/cache.h"
#include "math/cuadratic_bezier.h"
#include "math/cubic_bezier.h"

using namespace geom;
using namespace math;

static cubic_bezier crab_body_bezier(
    glm::vec3(-2, 0, 0),
    glm::vec3(-1.5f, 3, 0),
    glm::vec3(2.5f, 1, 0),
    glm::vec3(2, 0, 0));

cache::cache() :
  grid(10),
  crab_body(32, 16, crab_body_bezier) {

  }

