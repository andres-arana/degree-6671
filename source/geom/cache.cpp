#include "geom/cache.h"
#include "math/cuadraticBezier.h"

using namespace geom;
using namespace math;

static CuadraticBezier crabBodyBezier(
    glm::vec3(-2, 0, 0),
    glm::vec3(-1.5f, 3, 0),
    glm::vec3(2, 1, 0));

Cache::Cache() :
  grid(10),
  crabBody(32, 16, crabBodyBezier) {

  }

