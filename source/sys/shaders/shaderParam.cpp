#include "sys/shaders/shaderParam.h"

using namespace sys::shaders;

ShaderParam::ShaderParam(GLint handle) :
  handle(handle) {

}

bool ShaderParam::isAvailable() const {
  return handle >= 0;
}

GLuint ShaderParam::getHandle() const {
  return handle;
}
