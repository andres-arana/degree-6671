#ifndef __SYS_SHADERS_SHADER_H_INCLUDED__
#define __SYS_SHADERS_SHADER_H_INCLUDED__

#include <GL/glew.h>
#include <string>

namespace sys {
  namespace shaders {

    class Shader {
      public:
        Shader(GLuint type, const std::string &file);

        GLuint getHandle() const;

        virtual ~Shader();

      private:
        GLuint handle;
    };

  };

};

#endif
