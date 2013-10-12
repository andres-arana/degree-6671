#include "scene/floor.h"

using namespace scene;

Floor::Floor(
    const geom::Cache &geometries,
    const shaders::Cache &shaders) :
  geometries(geometries),
  shaders(shaders) {

  }

void Floor::render(const glm::mat4 &modelMatrix) {
  shaders.basic.bindDiffuseReflectivity(glm::vec3(0.4f, 0.4f, 0.6f));
  shaders.basic.bindAmbientReflectivity(glm::vec3(1, 1, 1));
  geometries.grid.render(modelMatrix, shaders.basic);
}
