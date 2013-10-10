#include "sys/shaders/fragmentShader.h"

using namespace sys::shaders;

FragmentShader::FragmentShader(const std::string &file) :
  Shader(GL_FRAGMENT_SHADER, file) {

}

FragmentShader::~FragmentShader() {

}
