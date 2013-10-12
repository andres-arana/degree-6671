#ifndef __SHADERS_SHADERPARAM_H_INCLUDED__
#define __SHADERS_SHADERPARAM_H_INCLUDED__

#include <GL/glew.h>

namespace sys {
  class ShaderParam {
    public:
      ShaderParam(GLint handle);

      bool isAvailable() const;

      GLuint getHandle() const;

    private:
      GLint handle;
  };
};

#endif
