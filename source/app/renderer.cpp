#include "app/renderer.h"
#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

app::Renderer::Renderer() :
  scene(geometries, shaders),
  rotatingCamera(glm::vec3(0, 0, 1.0f), 12.0f, shaders),
  fpsCamera(glm::vec3(12.0f, 0, 1.0f), shaders) {
    glClearColor(0.1f, 0.1f, 0.2f, 0.0f);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    currentCamera = &rotatingCamera;
  }

void app::Renderer::tick(float delta) {
  currentCamera->tick(delta);
}

void app::Renderer::render(sys::Context &context) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  currentCamera->use();

  const app::shaders::DiffuseShader &diffuseShader =
    shaders.getDiffuseShader();

  diffuseShader.bindProjectionMatrix(glm::infinitePerspective(
        52.0f, context.getWindow().getAspectRatio(), 0.1f));

  diffuseShader.bindLightPosition(glm::vec4(8.0f, 0.0f, 3.0f, 1.0f));

  diffuseShader.bindLightColor(glm::vec3(2.0f, 2.0f, 2.0f));

  glm::mat4 modelMatrix = glm::mat4(1.0f);
  scene.render(modelMatrix);

  context.getWindow().swapBuffers();
}

void app::Renderer::resize(int width, int height) {
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}

void app::Renderer::toggleCamera() {
  if (currentCamera == &rotatingCamera) {
    currentCamera = &fpsCamera;
  } else {
    currentCamera = &rotatingCamera;
  }
}

app::scene::Camera &app::Renderer::getCamera() {
  return *currentCamera;
}

