#ifndef __SHADERS_SHADER_H_INCLUDED__
#define __SHADERS_SHADER_H_INCLUDED__

#include <GL/glew.h>
#include <string>

namespace sys {
  class Shader {
    public:
      Shader(GLuint type, const std::string &file);

      Shader(const Shader &other) = delete;
      Shader &operator=(const Shader &other) = delete;

      GLuint getHandle() const;

      virtual ~Shader();

    private:
      GLuint handle;
  };
};

#endif
