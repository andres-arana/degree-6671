#ifndef __SHADERS_VERTEX_SHADER_H_INCLUDED__
#define __SHADERS_VERTEX_SHADER_H_INCLUDED__

#include "sys/shader.h"

namespace sys {
  class vertex_shader : public shader {
    public:
      vertex_shader(const std::string &file);

      vertex_shader(const vertex_shader &other) = delete;
      vertex_shader &operator=(const vertex_shader &other) = delete;

      virtual ~vertex_shader();
  };
};

#endif
