#include "sys/vertexShader.h"

using namespace sys;

VertexShader::VertexShader(const std::string &file) :
  Shader(GL_VERTEX_SHADER, file) {

}

VertexShader::~VertexShader() {

}
