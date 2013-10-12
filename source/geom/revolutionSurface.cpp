#include "geom/revolutionSurface.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

using namespace geom;

RevolutionSurface::RevolutionSurface(
    int angularSections,
    int longitudinalSections,
    const math::Function &f) {

  glm::vec3 rotationAxis(1.0f, 0, 0);
  auto angularIncrement = 360.0f / angularSections;
  auto longitudinalIncrement = 1.0f / (longitudinalSections - 1);

  for (int i = 0; i < longitudinalSections; i++) {
    auto x = i * longitudinalIncrement;
    auto original = f.apply(x);
    auto originalTangent = f.applyDerivate(x);
    auto originalNormal = glm::normalize(glm::vec3(-originalTangent.y, originalTangent.x, 0));

    for (int j = 0; j < angularSections; j++) {
      auto angle = j * angularIncrement;
      auto current = glm::rotate(original, angle, rotationAxis);
      vertexBuffer.push_back(current.x);
      vertexBuffer.push_back(current.y);
      vertexBuffer.push_back(current.z);

      auto currentNormal = glm::rotate(originalNormal, angle, rotationAxis);
      normalBuffer.push_back(currentNormal.x);
      normalBuffer.push_back(currentNormal.y);
      normalBuffer.push_back(currentNormal.z);
    }
  }

  for (int i = 0; i < longitudinalSections - 1; i++) {
    for (int j = 0; j < angularSections; j++) {
      indexBuffer.push_back(i * angularSections + j);
      indexBuffer.push_back(i * angularSections + j + angularSections);
    }
    indexBuffer.push_back(i * angularSections);
    indexBuffer.push_back((i + 1) * angularSections);

    if (i < longitudinalSections - 2) {
      indexBuffer.push_back((i + 2) * angularSections);
    }
  }
}

void RevolutionSurface::render(
    const glm::mat4 &modelMatrix,
    const sys::ShaderProgram &shader) const {

  shader.use();
  shader.bindModelMatrix(modelMatrix);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, &vertexBuffer[0]);
  glNormalPointer(GL_FLOAT, 0, &vertexBuffer[0]);

  glDrawElements(GL_TRIANGLE_STRIP, indexBuffer.size(), GL_UNSIGNED_INT, &indexBuffer[0]);
}
