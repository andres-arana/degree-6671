#include "geom/revolution_surface.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

using namespace geom;

revolution_surface::revolution_surface(
    int angular_sections,
    int longitudinal_sections,
    const math::parametric_curve &f) {

  glm::vec3 rotation_axis(1.0f, 0, 0);
  auto angular_increment = 360.0f / angular_sections;
  auto longitudinal_increment = 1.0f / (longitudinal_sections - 1);

  for (int i = 0; i < longitudinal_sections; i++) {
    auto x = i * longitudinal_increment;
    auto original = f(x);
    auto original_tangent = f.derivative(x);
    auto original_normal = glm::normalize(glm::vec3(-original_tangent.y, original_tangent.x, 0));

    for (int j = 0; j < angular_sections; j++) {
      auto angle = j * angular_increment;
      auto current = glm::rotate(original, angle, rotation_axis);
      vertex_buffer.push_back(current.x);
      vertex_buffer.push_back(current.y);
      vertex_buffer.push_back(current.z);

      auto current_normal = glm::rotate(original_normal, angle, rotation_axis);
      normal_buffer.push_back(current_normal.x);
      normal_buffer.push_back(current_normal.y);
      normal_buffer.push_back(current_normal.z);
    }
  }

  for (int i = 0; i < longitudinal_sections - 1; i++) {
    for (int j = 0; j < angular_sections; j++) {
      index_buffer.push_back(i * angular_sections + j);
      index_buffer.push_back(i * angular_sections + j + angular_sections);
    }
    index_buffer.push_back(i * angular_sections);
    index_buffer.push_back((i + 1) * angular_sections);

    if (i < longitudinal_sections - 2) {
      index_buffer.push_back((i + 2) * angular_sections);
    }
  }
}

void revolution_surface::render(
    const glm::mat4 &model_matrix,
    const sys::shader_program &shader) const {

  shader.use();
  shader.bind_model_matrix(model_matrix);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, &vertex_buffer[0]);
  glNormalPointer(GL_FLOAT, 0, &vertex_buffer[0]);

  glDrawElements(GL_TRIANGLE_STRIP, index_buffer.size(), GL_UNSIGNED_INT, &index_buffer[0]);
}
