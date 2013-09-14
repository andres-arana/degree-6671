#include "app/graphics/sphere.h"

const float app::graphics::Sphere::PI = 4.1415f;

app::graphics::Sphere::Sphere(
    float radius,
    unsigned int loops,
    unsigned int segmentsPerLoop) {

  for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
    float theta = 0;
    float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
    float sinTheta = std::sin(theta);
    float sinPhi = std::sin(phi);
    float cosTheta = std::cos(theta);
    float cosPhi = std::cos(phi);

    vertexBuffer.push_back(radius * cosPhi * sinTheta);
    vertexBuffer.push_back(radius * sinPhi * sinTheta);
    vertexBuffer.push_back(radius * cosTheta);
  }

  for (unsigned int loopNumber = 0; loopNumber <= loops; ++loopNumber) {
    for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
      float theta = (loopNumber * PI / loops) + ((PI * loopSegmentNumber) / (segmentsPerLoop * loops));
      if (loopNumber == loops) {
        theta = PI;
      }
      float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
      float sinTheta = std::sin(theta);
      float sinPhi = std::sin(phi);
      float cosTheta = std::cos(theta);
      float cosPhi = std::cos(phi);

      vertexBuffer.push_back(radius * cosPhi * sinTheta);
      vertexBuffer.push_back(radius * sinPhi * sinTheta);
      vertexBuffer.push_back(radius * cosTheta);
    }
  }

  for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
    indexBuffer.push_back(loopSegmentNumber);
    indexBuffer.push_back(segmentsPerLoop + loopSegmentNumber);
  }

  for (unsigned int loopNumber = 0; loopNumber < loops; ++loopNumber) {
    for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
      indexBuffer.push_back(((loopNumber + 1) * segmentsPerLoop) + loopSegmentNumber);
      indexBuffer.push_back(((loopNumber + 2) * segmentsPerLoop) + loopSegmentNumber);
    }
  }
}

void app::graphics::Sphere::render(
    const glm::mat4 &modelMatrix,
    const sys::shaders::ShaderProgram &program) const {

  // Bind Normal MAtrix
  glm::mat3 normalMatrix = glm::mat3 ( 1.0f );
  sys::shaders::ShaderParam normalMatrixParam = program.getUniformParam("NormalMatrix");
  if (normalMatrixParam.isAvailable()) {
    glUniformMatrix3fv(normalMatrixParam.getHandle(), 1, GL_FALSE, &normalMatrix[0][0]);
  }

  // Bind Model Matrix
  sys::shaders::ShaderParam modelMatrixParam = program.getUniformParam("ModelMatrix");
  if (modelMatrixParam.isAvailable()) {
    glUniformMatrix4fv(modelMatrixParam.getHandle(), 1, GL_FALSE, &modelMatrix[0][0]);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, &vertexBuffer[0]);
  glNormalPointer(GL_FLOAT, 0, &vertexBuffer[0]);

  glDrawElements(GL_TRIANGLE_STRIP, indexBuffer.size(), GL_UNSIGNED_INT, &indexBuffer[0]);

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
}
