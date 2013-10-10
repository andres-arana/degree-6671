#include "app/scene/floor.h"

using namespace app;
using namespace app::scene;

Floor::Floor(
    const geometries::Register &geometries, 
    const shaders::Register &shaders) :
  geometries(geometries),
  shader(shaders.getDiffuseShader()) {

  }

void Floor::render(const glm::mat4 &modelMatrix) {
  shader.bindDiffuseReflectivity(glm::vec3(0.2f, 0.2f, 0.2f));
  shader.bindAmbientReflectivity(glm::vec3(1, 1, 1));
  geometries.getGrid().render(modelMatrix, shader);
}
