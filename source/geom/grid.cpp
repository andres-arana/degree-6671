#include "geom/grid.h"

using namespace geom;

grid::grid(int size) :
  vertex_buffer(12 * (2 * size + 1)),
  index_buffer(4 * (2 * size + 1)) {
    for (int i = 0; i < size; i++) {
      int offset = 24 * i;

      offset = assign_vertex(offset, -size, i+1, 0);
      offset = assign_vertex(offset, size, i+1, 0);
      offset = assign_vertex(offset, -size, -(i+1), 0);
      offset = assign_vertex(offset, size, -(i+1), 0);
      offset = assign_vertex(offset, i+1, -size, 0);
      offset = assign_vertex(offset, i+1, size, 0);
      offset = assign_vertex(offset, -(i+1), -size, 0);
      offset = assign_vertex(offset, -(i+1), size, 0);
    }
    int offset = 24 * size;
    offset = assign_vertex(offset, -size, 0, 0);
    offset = assign_vertex(offset, size, 0, 0);
    offset = assign_vertex(offset, 0, -size, 0);
    offset = assign_vertex(offset, 0, size, 0);

    for (unsigned int i = 0; i < index_buffer.size(); i++) {
      index_buffer[i] = i;
    }
  }

void grid::render(
    const glm::mat4 &model_matrix,
    const sys::shader_program &shader) const {

  shader.use();
  shader.bind_model_matrix(model_matrix);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &vertex_buffer[0]);
  glDrawElements(GL_LINES, index_buffer.size(), GL_UNSIGNED_INT, &index_buffer[0]);
  glDisableClientState(GL_VERTEX_ARRAY);
}


unsigned int grid::assign_vertex(
    unsigned int offset,
    GLfloat x, GLfloat y, GLfloat z) {

  vertex_buffer[offset++] = x;
  vertex_buffer[offset++] = y;
  vertex_buffer[offset++] = z;
  return offset;
}

