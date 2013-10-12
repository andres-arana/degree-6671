#include "scene/floor.h"

using namespace scene;

floor::floor(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
  geometries(geometries),
  shaders(shaders) {

  }

void floor::render(const glm::mat4 &model_matrix) {
  shaders.basic.bind_diffuse_reflectivity(glm::vec3(0.4f, 0.4f, 0.6f));
  shaders.basic.bind_ambient_reflectivity(glm::vec3(1, 1, 1));
  shaders.basic.bind_specular_reflectivity(glm::vec3(0, 0, 0));
  shaders.basic.bind_specular_shininess(0);
  geometries.grid.render(model_matrix, shaders.basic);
}
