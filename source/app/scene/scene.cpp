#include "app/scene/scene.h"
#include <glm/gtc/matrix_transform.hpp> 

app::scene::Scene::Scene(
    sys::Window &window,
    sys::Input &input,
    const app::geometries::Register &geometries, 
    const app::shaders::Register &shaders) :
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

void app::scene::Scene::render() {
  glm::mat4 viewMatrix = currentCamera->use();

  glm::vec4 position = viewMatrix * glm::vec4(5, 2, 0, 1);

  shaders.getDiffuseShader().bindLightPosition(position);
  shaders.getDiffuseShader().bindDiffuseIntensity(glm::vec3(1.0f, 1.0f, 1.0f));
  shaders.getDiffuseShader().bindAmbientIntensity(glm::vec3(0.5f, 0.5f, 0.5f));

  glm::mat4 modelMatrix = glm::mat4(1.0f);
  floor.render(modelMatrix);

  shaders.getDiffuseShader().bindDiffuseReflectivity(glm::vec3(0.2f, 0.2f, 0.0f));
  shaders.getDiffuseShader().bindAmbientReflectivity(glm::vec3(0.0f, 0.5f, 0.0f));
  glm::mat4 m = glm::translate(modelMatrix, glm::vec3(0, 0, 2));
  geometries.getRevolutionSurface().render(m, shaders.getDiffuseShader());

  shaders.getDiffuseShader().bindDiffuseReflectivity(glm::vec3(0, 0, 0));
  shaders.getDiffuseShader().bindAmbientReflectivity(glm::vec3(10, 10, 10));
  m = glm::translate(modelMatrix, glm::vec3(5, 2, 0));
  m = glm::rotate(m, 90.0f, glm::vec3(0, 1, 0));
  m = glm::translate(m, glm::vec3(-0.5f, 0, 0));
  geometries.getLightBulb().render(m, shaders.getDiffuseShader());
}

void app::scene::Scene::tick(float delta) {
  currentCamera->tick(delta);
}

void app::scene::Scene::toggleCamera() {
  if (currentCamera == &rotatingCamera) {
    currentCamera = &fpsCamera;
  } else {
    currentCamera = &rotatingCamera;
  }
}
