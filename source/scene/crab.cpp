#include "scene/crab.h"

using namespace scene;

Crab::Crab(
    const geom::Cache &geometries,
    const shaders::Cache &shaders) :
  geometries(geometries),
  shaders(shaders) {

  }

void Crab::render(const glm::mat4 &modelMatrix) {
  shaders.basic.bindDiffuseReflectivity(glm::vec3(0.4f, 0.3f, 0.1f));
  shaders.basic.bindAmbientReflectivity(glm::vec3(0.0f, 0.5f, 0.0f));
  geometries.crabBody.render(modelMatrix, shaders.basic);
}
