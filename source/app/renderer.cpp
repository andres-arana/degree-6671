#include "app/renderer.h"
#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

app::Renderer::Renderer() {
  glClearColor(0.1f, 0.1f, 0.2f, 0.0f);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);

  diffuseShader.use();
}

void app::Renderer::render(sys::Context &context) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  diffuseShader.bindViewMatrix(glm::lookAt(
        glm::vec3(10.0, 0.0, 3.0),
        glm::vec3(0.0, 0.0, 0.0),
        glm::vec3(0.0, 0.0, 1.0)));

  diffuseShader.bindProjectionMatrix(glm::infinitePerspective(
        52.0f, context.getWindow().getAspectRatio(), 0.1f));

  diffuseShader.bindLightPosition(glm::vec4(8.0f, 0.0f, 3.0f, 1.0f));

  diffuseShader.bindLightColor(glm::vec3(2.0f, 2.0f, 2.0f));

  glm::mat4 modelMatrix = glm::mat4(1.0f);
  renderGrid(modelMatrix);
  renderArm(modelMatrix);

  context.getWindow().swapBuffers();
}

void app::Renderer::resize(int width, int height) {
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);
}

void app::Renderer::renderArmSection(const glm::mat4 &modelMatrix) {
  glm::mat4 m = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 3.0f));
  geometryRegister.getSphere().render(m, diffuseShader);

  m = glm::scale(modelMatrix, glm::vec3(0.6f, 0.6f, 3.0f));
  m = glm::translate(m, glm::vec3(0.0f, 0.0f, 0.5f));
  geometryRegister.getCube().render(m, diffuseShader);
}

void app::Renderer::renderGrid(const glm::mat4 &modelMatrix) {
  diffuseShader.bindLightReflectivity(glm::vec3(0.2f, 0.2f, 0.2f));
  geometryRegister.getGrid().render(modelMatrix, diffuseShader);
}

void app::Renderer::renderArm(const glm::mat4 &modelMatrix) {
  diffuseShader.bindLightReflectivity(glm::vec3(1.0f, 1.0f, 0.4f));
  glm::mat4 m = glm::scale(modelMatrix, glm::vec3(0.5f, 0.5f, 0.5f));

  // First arm section
  m = glm::rotate(m, 20.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  renderArmSection(m);

  // Second arm section
  m = glm::translate(m, glm::vec3(0.0f, 0.0f, 3.0f));
  m = glm::rotate(m, 20.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  renderArmSection(m);

  // Hand matrix definition
  glm::mat4 handMatrix = glm::translate(m, glm::vec3(0.0f, 0.0f, 3.0f));

  // Upper hand section
  m = glm::rotate(handMatrix, -45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  renderArmSection(m);

  // Lower hand section
  m = glm::rotate(handMatrix, 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  renderArmSection(m);
}
