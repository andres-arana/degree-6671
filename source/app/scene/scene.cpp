#include "app/scene/scene.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/constants.hpp> 

using namespace app;
using namespace app::scene;
using namespace sys;

Scene::Scene(
    Window &window,
    Input &input,
    const geometries::Register &geometries,
    const shaders::Register &shaders) :
  options(0, 0, 0),
  fpsCamera(window, input, glm::vec3(12.0f, 0, 1.0f), shaders),
  rotatingCamera(window, input, glm::vec3(0, 0, 1.0f), 12.0f, shaders),
  floor(geometries, shaders),
  light(geometries, shaders),
  crab(geometries, shaders),
  currentCamera(&rotatingCamera),
  rotation(0) {

  }

void Scene::render() {
  auto modelMatrix = glm::mat4(1.0f);
  auto viewMatrix = currentCamera->use();

  auto lightMatrix = glm::rotate(modelMatrix, rotation, glm::vec3(0, 0, 1));
  lightMatrix = glm::translate(lightMatrix, glm::vec3(4, 0, 2));
  light.use(viewMatrix, lightMatrix);

  floor.render(modelMatrix);

  auto crabMatrix = glm::translate(modelMatrix, glm::vec3(-2.0f, 0, 1.75f));
  crab.render(crabMatrix);
}

void Scene::tick(float delta) {
  currentCamera->tick(delta);
  rotation += (30 * delta);
  if (rotation > 360) {
    rotation -= 360;
  }
}

void app::scene::Scene::toggleCamera() {
  if (currentCamera == &rotatingCamera) {
    currentCamera = &fpsCamera;
  } else {
    currentCamera = &rotatingCamera;
  }
}
