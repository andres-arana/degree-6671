#include "geom/surface_patch.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

using namespace geom;

surface_patch::surface_patch(
    int u_sections,
    int v_sections,
    const math::parametric_surface &f) {

  auto u_increment = 1.0f / (u_sections - 1);
  auto v_increment = 1.0f / (v_sections - 1);

  for (int i = 0; i < u_sections; i++) {
    for (int j = 0; j < v_sections; j++) {
      auto domain = glm::vec2(i * u_increment, j * v_increment);

      auto value = f(domain);
      vertex_buffer.push_back(value.x);
      vertex_buffer.push_back(value.y);
      vertex_buffer.push_back(value.z);

      auto du = f.derivative_u(domain);
      auto dv = f.derivative_v(domain);
      auto normal = glm::normalize(glm::cross(du, dv));
      normal_buffer.push_back(normal.x);
      normal_buffer.push_back(normal.y);
      normal_buffer.push_back(normal.z);
    }
  }

  for (int i = 0; i < u_sections; i++) {
    for (int j = 0; j < v_sections; j++) {
      index_buffer.push_back(i * v_sections + j);
      index_buffer.push_back(i * v_sections + j + v_sections);
    }

    if (i < u_sections - 2) {
      index_buffer.push_back(i * v_sections + v_sections - 1 + v_sections);
      index_buffer.push_back((i + 1) * v_sections);
    }
  }
}

void surface_patch::render(
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
