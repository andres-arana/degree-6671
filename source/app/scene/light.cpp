#include "app/scene/light.h"

using namespace app;
using namespace app::scene;

Light::Light(const geometries::Register &geometries, const shaders::Register &shaders) :
  geometries(geometries),
  shader(shaders.getDiffuseShader()) {

  }

void Light::use(const glm::mat4 &viewMatrix, const glm::mat4 &modelMatrix) {
  auto position = viewMatrix * modelMatrix * glm::vec4(0, 0, 0, 1);
  shader.bindLightPosition(position);

  shader.bindDiffuseIntensity(glm::vec3(1, 1, 1));
  shader.bindAmbientIntensity(glm::vec3(0.5f, 0.5f, 0.5f));

  // Simple light bulb
  shader.use();
  shader.bindDiffuseReflectivity(glm::vec3(0, 0, 0));
  shader.bindAmbientReflectivity(glm::vec3(12, 12, 12));
  geometries.getLightBulb().render(modelMatrix, shader);
}

