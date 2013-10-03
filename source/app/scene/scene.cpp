#include "app/scene/scene.h"

app::scene::Scene::Scene(
    const app::geometries::Register &geometries, 
    const app::shaders::Register &shaders) :
  floor(geometries, shaders),
  arm(geometries, shaders) {

  }

void app::scene::Scene::render(const glm::mat4 &modelMatrix) {
  floor.render(modelMatrix);
  arm.render(modelMatrix);
}
