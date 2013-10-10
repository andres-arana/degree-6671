#include "app/shaders/diffuseShader.h"
#include <GL/glew.h>

app::shaders::DiffuseShader::DiffuseShader() :
  sys::shaders::ShaderProgram(
      new sys::shaders::VertexShader("source/app/shaders/diffuseShader.vert"),
      new sys::shaders::FragmentShader("source/app/shaders/diffuseShader.frag")) {

}

void app::shaders::DiffuseShader::bindViewMatrix(const glm::mat4 &viewMatrix) const {
  sys::shaders::ShaderParam param = getUniformParam("ViewMatrix");
  if (param.isAvailable()) {
    glUniformMatrix4fv(param.getHandle(), 1, GL_FALSE, &viewMatrix[0][0]);
  }
}

void app::shaders::DiffuseShader::bindProjectionMatrix(const glm::mat4 &projMatrix) const {
  sys::shaders::ShaderParam param = getUniformParam("ProjectionMatrix");
  if (param.isAvailable()) {
    glUniformMatrix4fv(param.getHandle(), 1, GL_FALSE, &projMatrix[0][0]); 
  }
}

void app::shaders::DiffuseShader::bindLightPosition(const glm::vec4 &lightPos) const {
  sys::shaders::ShaderParam param = getUniformParam("LightPosition");
  if (param.isAvailable()) {
    glUniform4fv(param.getHandle(), 1, &lightPos[0]); 
  }
}

void app::shaders::DiffuseShader::bindDiffuseIntensity(const glm::vec3 &lightInt) const {
  sys::shaders::ShaderParam param = getUniformParam("Ld");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }
}

void app::shaders::DiffuseShader::bindAmbientIntensity(const glm::vec3 &lightInt) const {
  sys::shaders::ShaderParam param = getUniformParam("La");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }

}


void app::shaders::DiffuseShader::bindDiffuseReflectivity(const glm::vec3 &lightInt) const {
  sys::shaders::ShaderParam param = getUniformParam("Kd");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }
}

void app::shaders::DiffuseShader::bindAmbientReflectivity(const glm::vec3 &lightInt) const {
  sys::shaders::ShaderParam param = getUniformParam("Ka");
  if (param.isAvailable()) {
    glUniform3fv(param.getHandle(), 1, &lightInt[0]); 
  }
}

void app::shaders::DiffuseShader::bindNormalMatrix(const glm::mat3 &normalMatrix) const {
  sys::shaders::ShaderParam param = getUniformParam("NormalMatrix");
  if (param.isAvailable()) {
    glUniformMatrix3fv(param.getHandle(), 1, GL_FALSE, &normalMatrix[0][0]);
  }
}

void app::shaders::DiffuseShader::bindModelMatrix(const glm::mat4 &modelMatrix) const {
  sys::shaders::ShaderParam param = getUniformParam("ModelMatrix");
  if (param.isAvailable()) {
    glUniformMatrix4fv(param.getHandle(), 1, GL_FALSE, &modelMatrix[0][0]);
  }

}

app::shaders::DiffuseShader::~DiffuseShader() {

}
