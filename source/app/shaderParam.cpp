#include "app/shaderParam.h"

app::ShaderParam::ShaderParam(GLuint handle) :
  handle(handle) {

}

bool app::ShaderParam::isAvailable() const {
  return handle >= 0;
}

GLuint app::ShaderParam::getHandle() const {
  return handle;
}
