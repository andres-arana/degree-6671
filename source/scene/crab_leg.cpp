#include "scene/crab_leg.h"
#include <glm/gtc/matrix_transform.hpp> 

using namespace scene;

crab_leg::crab_leg(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
  geometries(geometries),
  shaders(shaders) {

  }

void crab_leg::render(const glm::mat4 &model_matrix) {
  shaders.basic.bind_diffuse_reflectivity(glm::vec3(0.4f, 0.3f, 0.1f));
  shaders.basic.bind_ambient_reflectivity(glm::vec3(0.0f, 0.5f, 0.0f));
  shaders.basic.bind_specular_reflectivity(glm::vec3(0.1f));
  shaders.basic.bind_specular_shininess(10);

  geometries.crab_leg_section.render(model_matrix, shaders.basic);

  auto m = glm::translate(model_matrix, glm::vec3(0.8f, 0, 0));
  m = glm::rotate(m, 40.0f, glm::vec3(0, 1, 0));
  geometries.crab_leg_section.render(m, shaders.basic);

  m = glm::translate(m, glm::vec3(0.8f, 0, 0));
  m = glm::rotate(m, 40.0f, glm::vec3(0, 1, 0));
  geometries.crab_leg_section.render(m, shaders.basic);
}
