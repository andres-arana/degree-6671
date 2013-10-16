#include "geom/cache.h"
#include "math/bezier_surface.h"
#include "math/cuadratic_bezier.h"
#include "math/cubic_bezier.h"

using namespace geom;
using namespace math;

static bezier_surface crab_body_bezier(
    glm::vec3(0, 0, 0),
    glm::vec3(0, 0, 0),
    glm::vec3(0, 0, 0),
    glm::vec3(0, 0, 0),

    glm::vec3(0.25f, 2.5f, 0),
    glm::vec3(0.25f, 2.45f, 2.5f),
    glm::vec3(0.25f, -2.45f, 2.5f),
    glm::vec3(0.25f, -2.5f, 0),

    glm::vec3(3.75f, 2, 0),
    glm::vec3(3.75f, 1.95f, 2),
    glm::vec3(3.75f, -1.95f, 2),
    glm::vec3(3.75f, -2, 0),

    glm::vec3(4, 0, 0),
    glm::vec3(4, 0, 0),
    glm::vec3(4, 0, 0),
    glm::vec3(4, 0, 0));

static cubic_bezier crab_leg_section_bezier(
    glm::vec3(0, 0, 0),
    glm::vec3(0.25f, 0.35f, 0),
    glm::vec3(0.75f, 0.35f, 0),
    glm::vec3(1.0, 0, 0));

static cubic_bezier crab_leg_root_bezier(
    glm::vec3(0, 0, 0),
    glm::vec3(0.25f, 0.45f, 0),
    glm::vec3(0.75f, 0.45f, 0),
    glm::vec3(1.0, 0, 0));

static cubic_bezier crab_leg_finisher_bezier(
    glm::vec3(0, 0, 0),
    glm::vec3(0.25f, 0.35f, 0),
    glm::vec3(0.75f, 0.15f, 0),
    glm::vec3(1.0, 0, 0));

static cuadratic_bezier crab_eye_leader_bezier(
    glm::vec3(0, 0.125f, 0),
    glm::vec3(0.0625f, 0.0f, 0),
    glm::vec3(0.7f, 0.125f, 0));

static cuadratic_bezier crab_eye_bezier(
    glm::vec3(0, 0, 0),
    glm::vec3(0.25f, 0.5f, 0),
    glm::vec3(0.5f, 0, 0));

cache::cache() :
  grid(10),
  crab_body(32, 32, crab_body_bezier),
  crab_leg_root(12, 12, crab_leg_root_bezier),
  crab_leg_section(8, 8, crab_leg_section_bezier),
  crab_leg_finisher(8, 8, crab_leg_finisher_bezier),
  crab_eye_leader(8, 8, crab_eye_leader_bezier),
  crab_eye(16, 16, crab_eye_bezier) {

  }

