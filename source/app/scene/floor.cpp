#include "app/scene/floor.h"

app::scene::Floor::Floor(
    const app::geometries::Register &geometries, 
    const app::shaders::Register &shaders) :
  geometries(geometries),
  shader(shaders.getDiffuseShader()) {

  }

void app::scene::Floor::render(const glm::mat4 &modelMatrix) {
  shader.bindDiffuseReflectivity(glm::vec3(0.2f, 0.2f, 0.2f));
  shader.bindAmbientReflectivity(glm::vec3(1, 1, 1));
  geometries.getGrid().render(modelMatrix, shader);
}
