#ifndef __SHADERS_SHADERPARAM_H_INCLUDED__
#define __SHADERS_SHADERPARAM_H_INCLUDED__

#include <GL/glew.h>

namespace sys {
  class shader_param {
    public:
      shader_param(GLint handle);

      bool is_available() const;

      GLuint get_handle() const;

    private:
      GLint handle;
  };
};

#endif
