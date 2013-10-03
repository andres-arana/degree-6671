#include "app/scene/armSection.h"
#include <glm/gtc/matrix_transform.hpp> 

app::scene::ArmSection::ArmSection(
    const app::geometries::Register &geometries, 
    const app::shaders::Register &shaders) :
  geometries(geometries),
  shader(shaders.getDiffuseShader()) {

  }

void app::scene::ArmSection::render(const glm::mat4 &modelMatrix) {
  glm::mat4 m = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 3.0f));
  geometries.getSphere().render(m, shader);

  m = glm::scale(modelMatrix, glm::vec3(0.6f, 0.6f, 3.0f));
  m = glm::translate(m, glm::vec3(0.0f, 0.0f, 0.5f));
  geometries.getCube().render(m, shader);
}
