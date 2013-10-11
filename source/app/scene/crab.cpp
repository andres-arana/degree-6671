#include "app/scene/crab.h"

using namespace app;
using namespace app::scene;

Crab::Crab(
    const geometries::Register &geometries, 
    const shaders::Register &shaders) :
  geometries(geometries),
  shader(shaders.getDiffuseShader()) {

  }

void Crab::render(const glm::mat4 &modelMatrix) {
  shader.bindDiffuseReflectivity(glm::vec3(0.4f, 0.3f, 0.1f));
  shader.bindAmbientReflectivity(glm::vec3(0.0f, 0.5f, 0.0f));
  geometries.getRevolutionSurface().render(modelMatrix, shader);
}
