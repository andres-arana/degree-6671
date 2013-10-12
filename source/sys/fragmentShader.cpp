#include "sys/fragmentShader.h"

using namespace sys;

FragmentShader::FragmentShader(const std::string &file) :
  Shader(GL_FRAGMENT_SHADER, file) {

}

FragmentShader::~FragmentShader() {

}
