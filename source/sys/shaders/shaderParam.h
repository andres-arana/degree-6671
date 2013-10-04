#ifndef __SYS_SHADERS_SHADERPARAM_H_INCLUDED__
#define __SYS_SHADERS_SHADERPARAM_H_INCLUDED__

#include <GL/glew.h>

namespace sys {
  namespace shaders {

    class ShaderParam {
      public:
        ShaderParam(GLint handle);

        bool isAvailable() const;

        GLuint getHandle() const;

      private:
        GLint handle;
    };

  };
};

#endif
