#include "scene/crab_arm.h"
#include <glm/gtc/matrix_transform.hpp> 

using namespace scene;

crab_arm::crab_arm(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
  geometries(geometries),
  shaders(shaders) {

  }

void crab_arm::render(const glm::mat4 &model_matrix) {
  shaders.basic.bind_diffuse_reflectivity(glm::vec3(0.4f, 0.1f, 0.0f));
  shaders.basic.bind_ambient_reflectivity(glm::vec3(0.4f, 0.1f, 0.0f));
  shaders.basic.bind_specular_reflectivity(glm::vec3(0.1f));
  shaders.basic.bind_specular_shininess(10);

  geometries.crab_leg_root.render(model_matrix, shaders.basic);

  auto m = glm::translate(model_matrix, glm::vec3(0.8f, 0, 0));
  m = glm::rotate(m, 40.0f, glm::vec3(0, 1, 0));
  geometries.crab_leg_section.render(m, shaders.basic);

  auto pincer_base = glm::translate(m, glm::vec3(0.8f, 0, 0));
  m = glm::rotate(pincer_base, 40.0f, glm::vec3(0, 1, 0));
  geometries.crab_pincer_top.render(m, shaders.basic);

  m = glm::rotate(pincer_base, 45.0f, glm::vec3(0, 1, 0));
  geometries.crab_pincer_bot.render(m, shaders.basic);
}
