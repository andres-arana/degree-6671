#include "sys/shaders/fragmentShader.h"

sys::shaders::FragmentShader::FragmentShader(const std::string &file) :
  sys::shaders::Shader(GL_FRAGMENT_SHADER, file) {

}

sys::shaders::FragmentShader::~FragmentShader() {

}
