#include "sys/shader_param.h"

using namespace sys;

shader_param::shader_param(GLint handle) :
  handle(handle) {

}

bool shader_param::is_available() const {
  return handle >= 0;
}

GLuint shader_param::get_handle() const {
  return handle;
}
