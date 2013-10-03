#include "app/scene/arm.h"
#include <glm/gtc/matrix_transform.hpp> 

app::scene::Arm::Arm(
    const app::geometries::Register &geometries, 
    const app::shaders::DiffuseShader &shader) :
  geometries(geometries),
  shader(shader),
  armSection(geometries, shader) {

  }

void app::scene::Arm::render(const glm::mat4 &modelMatrix) {
  shader.bindLightReflectivity(glm::vec3(1.0f, 1.0f, 0.4f));
  glm::mat4 m = glm::scale(modelMatrix, glm::vec3(0.5f, 0.5f, 0.5f));

  // First arm section
  m = glm::rotate(m, 20.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  armSection.render(m);

  // Second arm section
  m = glm::translate(m, glm::vec3(0.0f, 0.0f, 3.0f));
  m = glm::rotate(m, 20.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  armSection.render(m);

  // Hand matrix definition
  glm::mat4 handMatrix = glm::translate(m, glm::vec3(0.0f, 0.0f, 3.0f));

  // Upper hand section
  m = glm::rotate(handMatrix, -45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  armSection.render(m);

  // Lower hand section
  m = glm::rotate(handMatrix, 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  armSection.render(m);
}
