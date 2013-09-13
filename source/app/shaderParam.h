#ifndef __APP_SHADERPARAM_H_INCLUDED__
#define __APP_SHADERPARAM_H_INCLUDED__

#include <GL/glew.h>

namespace app {

  class ShaderParam {
    public:
      ShaderParam(GLuint handle);

      bool isAvailable() const;

      GLuint getHandle() const;

    private:
      GLuint handle;
  };

};

#endif
