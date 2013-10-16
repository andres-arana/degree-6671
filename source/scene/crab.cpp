#include "scene/crab.h"
#include <glm/gtc/matrix_transform.hpp> 

using namespace scene;

crab::crab(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
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

  geometries.crab_body.render(model_matrix, shaders.basic);

  auto m = glm::rotate(model_matrix, 180.0f, glm::vec3(1, 0, 0));
  geometries.crab_body.render(m, shaders.basic);

  // Right legts
  m = glm::translate(model_matrix, glm::vec3(1.65f, 1.60f, 0.10f));
  m = glm::rotate(m, 120.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(2.25f, 1.60f, 0.10f));
  m = glm::rotate(m, 90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(2.85f, 1.40f, 0.10f));
  m = glm::rotate(m, 60.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  // Left legs
  m = glm::translate(model_matrix, glm::vec3(1.65f, -1.60f, 0.10f));
  m = glm::rotate(m, -120.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(2.25f, -1.60f, 0.10f));
  m = glm::rotate(m, -90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(2.65f, -1.40f, 0.10f));
  m = glm::rotate(m, -60.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  // Arms
  m = glm::translate(model_matrix, glm::vec3(0.60f, 1.2f, 0.40f));
  m = glm::rotate(m, 90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, 120.0f, glm::vec3(1, 0, 0));
  arm.render(m);

  m = glm::translate(model_matrix, glm::vec3(0.60f, -1.2f, 0.40f));
  m = glm::rotate(m, -90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -120.0f, glm::vec3(1, 0, 0));
  arm.render(m);

  // Eyes
  m = glm::translate(model_matrix, glm::vec3(1.0f, 0.55f, 1.00f));
  m = glm::rotate(m, -15.0f, glm::vec3(1, 0, 0));
  m = glm::rotate(m, -100.0f, glm::vec3(0, 1, 0));
  eye.render(m);

  m = glm::translate(model_matrix, glm::vec3(1.0f, -0.55f, 1.00f));
  m = glm::rotate(m, 15.0f, glm::vec3(1, 0, 0));
  m = glm::rotate(m, -100.0f, glm::vec3(0, 1, 0));
  eye.render(m);
}
