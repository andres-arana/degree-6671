#include "scene/light.h"

using namespace scene;

light::light(const shaders::cache &shaders) :
  shaders(shaders) {

  }

void light::use(const glm::mat4 &view_matrix, const glm::mat4 &model_matrix) {
  auto position = view_matrix * model_matrix * glm::vec4(0, 0, 0, 1);
  shaders.basic.bind_light_position(position);

  shaders.basic.bind_diffuse_intensity(glm::vec3(1, 1, 1));
  shaders.basic.bind_ambient_intensity(glm::vec3(0.75f, 0.75f, 0.75f));
  shaders.basic.bind_specular_intensity(glm::vec3(1, 1, 1));
}

