#include "app/renderer.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

app::Renderer::Renderer() :
  vertexShader(GL_VERTEX_SHADER, "source/app/shaders/diffuseShader.vert"),
  fragmentShader(GL_FRAGMENT_SHADER, "source/app/shaders/diffuseShader.frag"),
  program(vertexShader, fragmentShader),
  grid(10),
  sphere(1.0f, 32, 32) {

    glClearColor(0.1f, 0.1f, 0.2f, 0.0f);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    program.use();

    setupView();
    setupLights();
  }

void app::Renderer::render(sys::Context &context) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  setupProjection(context.getWindow().getAspectRatio());

  glm::mat4 modelMatrix = glm::mat4(1.0f);

  renderGrid(modelMatrix);
  renderArm(modelMatrix);

  context.getWindow().swapBuffers();
}

void app::Renderer::resize(int width, int height) {
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);
}

void app::Renderer::setupView() {
  // Setup view matrix
  glm::mat4 viewMatrix = glm::lookAt(
      glm::vec3(10.0, 0.0, 3.0),
      glm::vec3(0.0, 0.0, 0.0),
      glm::vec3(0.0, 0.0, 1.0));

  sys::shaders::ShaderParam viewMatrixParam = program.getUniformParam("ViewMatrix");
  if (viewMatrixParam.isAvailable()) {
    glUniformMatrix4fv(viewMatrixParam.getHandle(), 1, GL_FALSE, &viewMatrix[0][0]);
  }
}

void app::Renderer::setupProjection(float aspectRatio) {
  // Setup projection matrix
  glm::mat4 projMatrix = glm::infinitePerspective(
      52.0f, aspectRatio, 0.1f);

  sys::shaders::ShaderParam projMatrixParam = program.getUniformParam("ProjectionMatrix");
  if (projMatrixParam.isAvailable()) {
    glUniformMatrix4fv( projMatrixParam.getHandle(), 1, GL_FALSE, &projMatrix[0][0]); 
  }
}

void app::Renderer::setupLights() {
  // Setup light settings
  glm::vec4 lightPos = glm::vec4(8.0f, 0.0f, 3.0f, 1.0f);
  sys::shaders::ShaderParam lightPosParam = program.getUniformParam("LightPosition");
  if (lightPosParam.isAvailable()) {
    glUniform4fv(lightPosParam.getHandle(), 1, &lightPos[0]); 
  }

  // Setup light color
  glm::vec3 lightInt = glm::vec3(2.0f, 2.0f, 2.0f);
  sys::shaders::ShaderParam lightIntParam = program.getUniformParam("Ld");
  if (lightIntParam.isAvailable()) {
    glUniform3fv( lightIntParam.getHandle(), 1, &lightInt[0]); 
  }
}

void app::Renderer::setupLightColors(float red, float green, float blue) {
  // Setup light color
  glm::vec3 lightInt = glm::vec3(red, green, blue);
  sys::shaders::ShaderParam lightIntParam = program.getUniformParam("Kd");
  if (lightIntParam.isAvailable()) {
    glUniform3fv( lightIntParam.getHandle(), 1, &lightInt[0]); 
  }
}

void app::Renderer::renderArmSection(const glm::mat4 &modelMatrix) {
  glm::mat4 m = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 3.0f));
  sphere.render(m, program);

  m = glm::scale(modelMatrix, glm::vec3(0.6f, 0.6f, 3.0f));
  m = glm::translate(m, glm::vec3(0.0f, 0.0f, 0.5f));
  cube.render(m, program);
}

void app::Renderer::renderGrid(const glm::mat4 &modelMatrix) {
  setupLightColors(0.2f, 0.2f, 0.2f);
  grid.render(modelMatrix, program);
}

void app::Renderer::renderArm(const glm::mat4 &modelMatrix) {
  setupLightColors(1.0f, 1.0f, 0.4f);
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
