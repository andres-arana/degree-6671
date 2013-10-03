#include "sys/shaders/vertexShader.h"

sys::shaders::VertexShader::VertexShader(const std::string &file) :
  sys::shaders::Shader(GL_VERTEX_SHADER, file) {

}

sys::shaders::VertexShader::~VertexShader() {

}
