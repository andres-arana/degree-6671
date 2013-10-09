#include "app/scene/scene.h"

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
  arm(geometries, shaders),
  currentCamera(&rotatingCamera) {

    glClearColor(0.1f, 0.1f, 0.2f, 0.0f);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

  }

void app::scene::Scene::render() {
  currentCamera->use();

  shaders.getDiffuseShader().bindLightPosition(glm::vec4(8.0f, 0.0f, 3.0f, 1.0f));
  shaders.getDiffuseShader().bindLightColor(glm::vec3(2.0f, 2.0f, 2.0f));

  glm::mat4 modelMatrix = glm::mat4(1.0f);
  floor.render(modelMatrix);
  arm.render(modelMatrix);
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
