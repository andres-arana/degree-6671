#include "geom/cache.h"
#include "math/cuadratic_bezier.h"
#include "math/cubic_bezier.h"

using namespace geom;
using namespace math;

static cubic_bezier crab_body_bezier(
    glm::vec3(-2, 0, 0),
    glm::vec3(-1.75f, 3, 0),
    glm::vec3(2.65f, 1.0f, 0),
    glm::vec3(2, 0, 0));

static cubic_bezier crab_leg_section_bezier(
    glm::vec3(0, 0, 0),
    glm::vec3(0.25f, 0.35f, 0),
    glm::vec3(0.75f, 0.35f, 0),
    glm::vec3(1.0, 0, 0));

cache::cache() :
  grid(10),
  crab_body(48, 48, crab_body_bezier),
  crab_leg_section(32, 32, crab_leg_section_bezier) {

  }

