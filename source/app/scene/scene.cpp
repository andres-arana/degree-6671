#include "app/scene/scene.h"

app::scene::Scene::Scene(
    const app::geometries::Register &geometries, 
    const app::shaders::DiffuseShader &shader) :
  floor(geometries, shader),
  arm(geometries, shader) {

  }

void app::scene::Scene::render(const glm::mat4 &modelMatrix) {
  floor.render(modelMatrix);
  arm.render(modelMatrix);
}
