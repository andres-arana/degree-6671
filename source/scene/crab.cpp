#include "scene/crab.h"

using namespace scene;

crab::crab(
    const geom::cache &geometries,
    const shaders::cache &shaders) :
  geometries(geometries),
  shaders(shaders) {

  }

void crab::render(const glm::mat4 &model_matrix) {
  shaders.basic.bind_diffuse_reflectivity(glm::vec3(0.4f, 0.3f, 0.1f));
  shaders.basic.bind_ambient_reflectivity(glm::vec3(0.0f, 0.5f, 0.0f));
  geometries.crab_body.render(model_matrix, shaders.basic);
}
