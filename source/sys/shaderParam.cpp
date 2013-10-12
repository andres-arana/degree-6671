#include "sys/shaderParam.h"

using namespace sys;

ShaderParam::ShaderParam(GLint handle) :
  handle(handle) {

}

bool ShaderParam::isAvailable() const {
  return handle >= 0;
}

GLuint ShaderParam::getHandle() const {
  return handle;
}
