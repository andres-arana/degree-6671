#include "geom/cache.h"
#include "math/bezier_surface.h"
#include "math/cuadratic_bezier.h"
#include "math/cubic_bezier.h"

using namespace geom;
using namespace math;

static bezier_surface crab_body_surface(
    glm::vec3(0, 0, 0),
    glm::vec3(0, 0, 0),
    glm::vec3(0, 0, 0),
    glm::vec3(0, 0, 0),

    glm::vec3(-0.1f, 2.5f, 0),
    glm::vec3(-0.1f, 2.45f, 2.5f),
    glm::vec3(-0.1f, -2.45f, 2.5f),
    glm::vec3(-0.1f, -2.5f, 0),

    glm::vec3(4.0f, 2, 0),
    glm::vec3(4.0f, 1.95f, 2.0f),
    glm::vec3(4.0f, -1.95f, 2.0f),
    glm::vec3(4.0f, -2, 0),

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

static bezier_surface crab_pincer_top_surface(
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),

    glm::vec3(0.25f, 0.75f, 0.0f),
    glm::vec3(0.25f, 0.0f, 1.5f),
    glm::vec3(0.25f, 0.0f, 1.5f),
    glm::vec3(0.25f, -0.75f, 0.0f),

    glm::vec3(1.5f, 0.15f, 0.0f),
    glm::vec3(1.5f, 0.0f, 0.75f),
    glm::vec3(1.5f, 0.0f, 0.75f),
    glm::vec3(1.5f, -0.15f, 0.0f),

    glm::vec3(2.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 0.0f, 0.0f));

static bezier_surface crab_pincer_bot_surface(
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),

    glm::vec3(0.25f, 0.55f, 0.0f),
    glm::vec3(0.25f, 0.0f, -1.5f),
    glm::vec3(0.25f, 0.0f, -1.5f),
    glm::vec3(0.25f, -0.55f, 0.0f),

    glm::vec3(1.25f, 0.05f, 0.0f),
    glm::vec3(1.25f, 0.0f, -0.75f),
    glm::vec3(1.25f, 0.0f, -0.75f),
    glm::vec3(1.25f, -0.05f, 0.0f),

    glm::vec3(1.5f, 0.0f, 0.0f),
    glm::vec3(1.5f, 0.0f, 0.0f),
    glm::vec3(1.5f, 0.0f, 0.0f),
    glm::vec3(1.5f, 0.0f, 0.0f));

cache::cache() :
  grid(10),
  crab_body(64, 64, crab_body_surface),
  crab_leg_root(16, 16, crab_leg_root_bezier),
  crab_leg_section(16, 16, crab_leg_section_bezier),
  crab_leg_finisher(16, 16, crab_leg_finisher_bezier),
  crab_eye_leader(16, 16, crab_eye_leader_bezier),
  crab_eye(32, 32, crab_eye_bezier),
  crab_pincer_top(32, 32, crab_pincer_top_surface),
  crab_pincer_bot(32, 32, crab_pincer_bot_surface) {

  }

