#ifndef __SHADERS_SHADER_H_INCLUDED__
#define __SHADERS_SHADER_H_INCLUDED__

#include <GL/glew.h>
#include <string>

namespace sys {
  class shader {
    public:
      shader(GLuint type, const std::string &file);

      shader(const shader &other) = delete;
      shader &operator=(const shader &other) = delete;

      GLuint get_handle() const;

      virtual ~shader();

    private:
      GLuint handle;
  };
};

#endif
