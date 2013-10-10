#include "app/scene/scene.h"
#include <glm/gtc/matrix_transform.hpp> 

using namespace app;
using namespace app::scene;
using namespace sys;

Scene::Scene(
    Window &window,
    Input &input,
    const geometries::Register &geometries, 
    const shaders::Register &shaders) :
  geometries(geometries),
  shaders(shaders),
  fpsCamera(window, input, glm::vec3(12.0f, 0, 1.0f), shaders),
  rotatingCamera(window, input, glm::vec3(0, 0, 1.0f), 12.0f, shaders),
  floor(geometries, shaders),
  currentCamera(&rotatingCamera),
  rotation(0) {

    glClearColor(0.1f, 0.1f, 0.2f, 0.0f);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

  }

void Scene::render() {
  auto viewMatrix = currentCamera->use();

  auto position = viewMatrix * glm::vec4(5, 2, 0, 1);

  shaders.getDiffuseShader().bindLightPosition(position);
  shaders.getDiffuseShader().bindDiffuseIntensity(glm::vec3(1.0f, 1.0f, 1.0f));
  shaders.getDiffuseShader().bindAmbientIntensity(glm::vec3(0.5f, 0.5f, 0.5f));

  auto modelMatrix = glm::mat4(1.0f);
  floor.render(modelMatrix);

  shaders.getDiffuseShader().bindDiffuseReflectivity(glm::vec3(0.2f, 0.2f, 0.0f));
  shaders.getDiffuseShader().bindAmbientReflectivity(glm::vec3(0.0f, 0.5f, 0.0f));
  auto m = glm::translate(modelMatrix, glm::vec3(0, 0, 2));
  geometries.getRevolutionSurface().render(m, shaders.getDiffuseShader());

  shaders.getDiffuseShader().bindDiffuseReflectivity(glm::vec3(0, 0, 0));
  shaders.getDiffuseShader().bindAmbientReflectivity(glm::vec3(10, 10, 10));
  m = glm::translate(modelMatrix, glm::vec3(5, 2, 0));
  m = glm::rotate(m, 90.0f, glm::vec3(0, 1, 0));
  m = glm::translate(m, glm::vec3(-0.5f, 0, 0));
  geometries.getLightBulb().render(m, shaders.getDiffuseShader());
}

void Scene::tick(float delta) {
  currentCamera->tick(delta);
}

void app::scene::Scene::toggleCamera() {
  if (currentCamera == &rotatingCamera) {
    currentCamera = &fpsCamera;
  } else {
    currentCamera = &rotatingCamera;
  }
}
