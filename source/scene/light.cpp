#include "scene/light.h"

using namespace scene;

Light::Light(const shaders::Cache &shaders) :
  shaders(shaders) {

  }

void Light::use(const glm::mat4 &viewMatrix, const glm::mat4 &modelMatrix) {
  auto position = viewMatrix * modelMatrix * glm::vec4(0, 0, 0, 1);
  shaders.basic.bindLightPosition(position);

  shaders.basic.bindDiffuseIntensity(glm::vec3(1, 1, 1));
  shaders.basic.bindAmbientIntensity(glm::vec3(0.5f, 0.5f, 0.5f));
}

