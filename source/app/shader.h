#ifndef __APP_SHADER_H_INCLUDED__
#define __APP_SHADER_H_INCLUDED__

#include <GL/glew.h>
#include <string>

namespace app {

  class Shader {
    public:
      Shader(GLuint type, const std::string &file);

      GLuint getHandle() const;

    private:
      GLuint handle;
  };

};

#endif
