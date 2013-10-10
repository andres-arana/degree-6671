#include "app/geometries/cube.h"

const GLfloat app::geometries::Cube::vertexBuffer[] = {
  0.5f, 0.5f, -0.5f,
  0.5f, -0.5f, -0.5f,
  -0.5f, -0.5f, -0.5f,
  -0.5f, 0.5f, -0.5f,
  0.5f, 0.5f, 0.5f,
  0.5f, -0.5f, 0.5f,
  -0.5f, -0.5f, 0.5f,
  -0.5f, 0.5f, 0.5f
};

const GLfloat app::geometries::Cube::normalBuffer[] = {
  0.5f, 0.5f, 0.0f,
  0.5f, -0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  -0.5f, 0.5f, 0.0f,
  0.5f, 0.5f, 0.0f,
  0.5f, -0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  -0.5f, 0.5f, 0.0f
};

const GLuint app::geometries::Cube::indexBuffer[] = {
  0, 1, 2, 3,
  4, 5, 6, 7,
  0, 4, 5, 1,
  1, 5, 6, 2,
  2, 6, 7, 3,
  3, 7, 4, 0
};

const unsigned int app::geometries::Cube::indexBufferSize = 24;

void app::geometries::Cube::render(
    const glm::mat4 &modelMatrix,
    const sys::shaders::ShaderProgram &shader) const {

  shader.bindModelMatrix(modelMatrix);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, vertexBuffer);
  glNormalPointer(GL_FLOAT, 0, normalBuffer);

  glDrawElements(GL_QUADS, indexBufferSize, GL_UNSIGNED_INT, indexBuffer);

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
}
