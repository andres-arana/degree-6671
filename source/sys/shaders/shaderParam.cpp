#include "sys/shaders/shaderParam.h"

sys::shaders::ShaderParam::ShaderParam(GLuint handle) :
  handle(handle) {

}

bool sys::shaders::ShaderParam::isAvailable() const {
  return handle >= 0;
}

GLuint sys::shaders::ShaderParam::getHandle() const {
  return handle;
}
