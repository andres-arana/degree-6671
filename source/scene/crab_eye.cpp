#include "scene/crab_eye.h"
#include <glm/gtc/matrix_transform.hpp> 

using namespace scene;

crab_eye::crab_eye(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
  geometries(geometries),
  shaders(shaders) {

  }

void crab_eye::render(const glm::mat4 &model_matrix) {
  shaders.basic.bind_diffuse_reflectivity(glm::vec3(0.4f, 0.3f, 0.1f));
  shaders.basic.bind_ambient_reflectivity(glm::vec3(0.5f, 0.5f, 0.0f));
  shaders.basic.bind_specular_reflectivity(glm::vec3(0.1f));
  shaders.basic.bind_specular_shininess(10);

  geometries.crab_eye_leader.render(model_matrix, shaders.basic);

  shaders.basic.bind_specular_shininess(50);
  shaders.basic.bind_specular_reflectivity(glm::vec3(0.5f));
  auto m = glm::translate(model_matrix, glm::vec3(0.65f, 0, 0));
  geometries.crab_eye.render(m, shaders.basic);
}
