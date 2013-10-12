#include "sys/fragment_shader.h"

using namespace sys;

fragment_shader::fragment_shader(const std::string &file) :
  shader(GL_FRAGMENT_SHADER, file) {

}

fragment_shader::~fragment_shader() {

}
