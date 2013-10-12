#include "sys/vertex_shader.h"

using namespace sys;

vertex_shader::vertex_shader(const std::string &file) :
  shader(GL_VERTEX_SHADER, file) {

}

vertex_shader::~vertex_shader() {

}
