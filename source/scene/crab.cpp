#include "scene/crab.h"
#include "math/linear_interpolation.h"
#include <glm/gtc/matrix_transform.hpp> 

using namespace scene;

static math::linear_interpolation<float> leg_rotation_y({
    std::make_pair(3.0f, -10.0f),
    std::make_pair(2.0f, -10.0f),
    std::make_pair(1.0f, -20.0f),
    std::make_pair(0.0f, -10.0f)
    });

static math::linear_interpolation<float> leg_rotation_z({
    std::make_pair(3.0f, 0.0f),
    std::make_pair(2.0f, 20.0f),
    std::make_pair(1.0f, 10.0f),
    std::make_pair(0.0f, 0.0f)
    });

crab::crab(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
  time(0.0f, 3.0f),
  distance(0),
  geometries(geometries),
  shaders(shaders),
  leg(geometries, shaders),
  eye(geometries, shaders),
  arm(geometries, shaders) {

  }

void crab::render(const glm::mat4 &model_matrix) {
  shaders.basic.bind_diffuse_reflectivity(glm::vec3(0.4f, 0.30f, 0.10f));
  shaders.basic.bind_ambient_reflectivity(glm::vec3(0.5f, 0.3f, 0.0f));
  shaders.basic.bind_specular_reflectivity(glm::vec3(0.5f));
  shaders.basic.bind_specular_shininess(100);

  auto base_matrix = glm::translate(model_matrix, glm::vec3(-distance, 0, 0));

  geometries.crab_body.render(base_matrix, shaders.basic);

  auto m = glm::rotate(base_matrix, 180.0f, glm::vec3(1, 0, 0));
  geometries.crab_body.render(m, shaders.basic);

  // Right legts
  auto frame_time = time.get();
  auto rotation_y = leg_rotation_y(frame_time);
  auto rotation_z = leg_rotation_z(frame_time);
  m = glm::translate(base_matrix, glm::vec3(1.65f, 1.60f, 0.10f));
  m = glm::rotate(m, 120.0f + rotation_z, glm::vec3(0, 0, 1));
  m = glm::rotate(m, rotation_y, glm::vec3(0, 1, 0));
  leg.render(m);

  frame_time = time.displaced_get(0.4f);
  rotation_y = leg_rotation_y(frame_time);
  rotation_z = leg_rotation_z(frame_time);
  m = glm::translate(base_matrix, glm::vec3(2.25f, 1.60f, 0.10f));
  m = glm::rotate(m, 90.0f + rotation_z, glm::vec3(0, 0, 1));
  m = glm::rotate(m, rotation_y, glm::vec3(0, 1, 0));
  leg.render(m);

  frame_time = time.displaced_get(0.8f);
  rotation_y = leg_rotation_y(frame_time);
  rotation_z = leg_rotation_z(frame_time);
  m = glm::translate(base_matrix, glm::vec3(2.85f, 1.40f, 0.10f));
  m = glm::rotate(m, 60.0f + rotation_z, glm::vec3(0, 0, 1));
  m = glm::rotate(m, rotation_y, glm::vec3(0, 1, 0));
  leg.render(m);

  // Left legs
  frame_time = time.displaced_get(1.2f);
  rotation_y = leg_rotation_y(frame_time);
  rotation_z = leg_rotation_z(frame_time);
  m = glm::translate(base_matrix, glm::vec3(1.65f, -1.60f, 0.10f));
  m = glm::rotate(m, -120.0f - rotation_z, glm::vec3(0, 0, 1));
  m = glm::rotate(m, rotation_y, glm::vec3(0, 1, 0));
  leg.render(m);

  frame_time = time.displaced_get(1.6f);
  rotation_y = leg_rotation_y(frame_time);
  rotation_z = leg_rotation_z(frame_time);
  m = glm::translate(base_matrix, glm::vec3(2.25f, -1.60f, 0.10f));
  m = glm::rotate(m, -90.0f - rotation_z, glm::vec3(0, 0, 1));
  m = glm::rotate(m, rotation_y, glm::vec3(0, 1, 0));
  leg.render(m);

  frame_time = time.displaced_get(2.0f);
  rotation_y = leg_rotation_y(frame_time);
  rotation_z = leg_rotation_z(frame_time);
  m = glm::translate(base_matrix, glm::vec3(2.65f, -1.40f, 0.10f));
  m = glm::rotate(m, -60.0f - rotation_z, glm::vec3(0, 0, 1));
  m = glm::rotate(m, rotation_y, glm::vec3(0, 1, 0));
  leg.render(m);

  // Arms
  m = glm::translate(base_matrix, glm::vec3(0.60f, 1.2f, 0.40f));
  m = glm::rotate(m, 90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, 120.0f, glm::vec3(1, 0, 0));
  arm.render(m);

  m = glm::translate(base_matrix, glm::vec3(0.60f, -1.2f, 0.40f));
  m = glm::rotate(m, -90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -120.0f, glm::vec3(1, 0, 0));
  arm.render(m);

  // Eyes
  m = glm::translate(base_matrix, glm::vec3(1.0f, 0.55f, 1.00f));
  m = glm::rotate(m, -15.0f, glm::vec3(1, 0, 0));
  m = glm::rotate(m, -100.0f, glm::vec3(0, 1, 0));
  eye.render(m);

  m = glm::translate(base_matrix, glm::vec3(1.0f, -0.55f, 1.00f));
  m = glm::rotate(m, 15.0f, glm::vec3(1, 0, 0));
  m = glm::rotate(m, -100.0f, glm::vec3(0, 1, 0));
  eye.render(m);
}

void crab::tick(float t) {
  time.advance(t);
  distance += 0.5f * t;
}
