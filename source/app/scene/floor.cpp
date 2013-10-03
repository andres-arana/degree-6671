#include "app/scene/floor.h"

app::scene::Floor::Floor(
    const app::geometries::Register &geometries, 
    const app::shaders::DiffuseShader &shader) :
  geometries(geometries),
  shader(shader) {

  }

void app::scene::Floor::render(const glm::mat4 &modelMatrix) {
  shader.bindLightReflectivity(glm::vec3(0.2f, 0.2f, 0.2f));
  geometries.getGrid().render(modelMatrix, shader);
}
