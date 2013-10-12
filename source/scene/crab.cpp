#include "scene/crab.h"
#include <glm/gtc/matrix_transform.hpp> 

using namespace scene;

crab::crab(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
  geometries(geometries),
  shaders(shaders),
  leg(geometries, shaders) {

  }

void crab::render(const glm::mat4 &model_matrix) {
  shaders.basic.bind_diffuse_reflectivity(glm::vec3(0.2f, 0.2f, 0.4f));
  shaders.basic.bind_ambient_reflectivity(glm::vec3(0.3f, 0.4f, 0.5f));
  shaders.basic.bind_specular_reflectivity(glm::vec3(0.2f));
  shaders.basic.bind_specular_shininess(10);
  geometries.crab_body.render(model_matrix, shaders.basic);

  auto m = glm::translate(model_matrix, glm::vec3(-0.5f, 1.45f, -0.25f));
  m = glm::rotate(m, 120.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(0.2f, 1.45f, -0.25f));
  m = glm::rotate(m, 90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(0.75f, 1.25f, -0.25f));
  m = glm::rotate(m, 60.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(-0.5f, -1.45f, -0.25f));
  m = glm::rotate(m, -120.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(0.2f, -1.45f, -0.25f));
  m = glm::rotate(m, -90.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(0.75f, -1.25f, -0.25f));
  m = glm::rotate(m, -60.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -10.0f, glm::vec3(0, 1, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(-1.20f, 1.0f, 0.80f));
  m = glm::rotate(m, 100.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, 120.0f, glm::vec3(1, 0, 0));
  leg.render(m);

  m = glm::translate(model_matrix, glm::vec3(-1.20f, -1.0f, 0.80f));
  m = glm::rotate(m, -100.0f, glm::vec3(0, 0, 1));
  m = glm::rotate(m, -120.0f, glm::vec3(1, 0, 0));
  leg.render(m);
}
