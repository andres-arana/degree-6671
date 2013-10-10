#include "app/shaders/diffuseShader.h"
#include <GL/glew.h>

using namespace app::shaders;
using namespace sys::shaders;

DiffuseShader::DiffuseShader() :
  ShaderProgram(
      new VertexShader("source/app/shaders/diffuseShader.vert"),
      new FragmentShader("source/app/shaders/diffuseShader.frag")) {

  }

void DiffuseShader::bindViewMatrix(const glm::mat4 &viewMatrix) const {
  auto param = getUniformParam("ViewMatrix");
  if (param.isAvailable()) {
    glUniformMatrix4fv(param.getHandle(), 1, GL_FALSE, &viewMatrix[0][0]);
  }
}

void DiffuseShader::bindProjectionMatrix(const glm::mat4 &projMatrix) const {
  auto param = getUniformParam("ProjectionMatrix");
  if (param.isAvailable()) {
    glUniformMatrix4fv(param.getHandle(), 1, GL_FALSE, &projMatrix[0][0]); 
  }
}

void DiffuseShader::bindLightPosition(const glm::vec4 &lightPos) const {
  auto param = getUniformParam("LightPosition");
  if (param.isAvailable()) {
    glUniform4fv(param.getHandle(), 1, &lightPos[0]); 
  }
}

void DiffuseShader::bindDiffuseIntensity(const glm::vec3 &lightInt) const {
  auto param = getUniformParam("Ld");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }
}

void DiffuseShader::bindAmbientIntensity(const glm::vec3 &lightInt) const {
  auto param = getUniformParam("La");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }

}


void DiffuseShader::bindDiffuseReflectivity(const glm::vec3 &lightInt) const {
  auto param = getUniformParam("Kd");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }
}

void DiffuseShader::bindAmbientReflectivity(const glm::vec3 &lightInt) const {
  auto param = getUniformParam("Ka");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }
}

void DiffuseShader::bindModelMatrix(const glm::mat4 &modelMatrix) const {
  auto param = getUniformParam("ModelMatrix");
  if (param.isAvailable()) {
    glUniformMatrix4fv(param.getHandle(), 1, GL_FALSE, &modelMatrix[0][0]);
  }

}

DiffuseShader::~DiffuseShader() {

}
