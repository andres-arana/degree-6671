#include "app/geometries/grid.h"

app::geometries::Grid::Grid(int size) :
  vertexBuffer(12 * (2 * size + 1)),
  indexBuffer(4 * (2 * size + 1)) {
    // Compute vertex positions and fill vertex buffer
    for (int i = 0; i < size; i++) {
      int offset = 24 * i;

      offset = assignVertex(offset, -size, i+1, 0);
      offset = assignVertex(offset, size, i+1, 0);
      offset = assignVertex(offset, -size, -(i+1), 0);
      offset = assignVertex(offset, size, -(i+1), 0);
      offset = assignVertex(offset, i+1, -size, 0);
      offset = assignVertex(offset, i+1, size, 0);
      offset = assignVertex(offset, -(i+1), -size, 0);
      offset = assignVertex(offset, -(i+1), size, 0);
    }
    int offset = 24 * size;
    offset = assignVertex(offset, -size, 0, 0);
    offset = assignVertex(offset, size, 0, 0);
    offset = assignVertex(offset, 0, -size, 0);
    offset = assignVertex(offset, 0, size, 0);

    // The vertices are in order already
    for (unsigned int i = 0; i < indexBuffer.size(); i++) {
      indexBuffer[i] = i;
    }
  }

void app::geometries::Grid::render(
    const glm::mat4 &modelMatrix, 
    const sys::shaders::ShaderProgram &shader) const {

  shader.use();
  shader.bindModelMatrix(modelMatrix);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &vertexBuffer[0]);
  glDrawElements(GL_LINES, indexBuffer.size(), GL_UNSIGNED_INT, &indexBuffer[0]);
  glDisableClientState(GL_VERTEX_ARRAY);
}


unsigned int app::geometries::Grid::assignVertex(unsigned int offset, GLfloat x, GLfloat y, GLfloat z) {
  vertexBuffer[offset++] = x;
  vertexBuffer[offset++] = y;
  vertexBuffer[offset++] = z;
  return offset;
}

