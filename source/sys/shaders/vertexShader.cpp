#include "sys/shaders/vertexShader.h"

using namespace sys::shaders;

VertexShader::VertexShader(const std::string &file) :
  Shader(GL_VERTEX_SHADER, file) {

}

VertexShader::~VertexShader() {

}
