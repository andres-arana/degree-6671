#ifndef __SHADERS_FRAGMENT_SHADER_H_INCLUDED__
#define __SHADERS_FRAGMENT_SHADER_H_INCLUDED__

#include "sys/shader.h"

namespace sys {
  class fragment_shader : public shader {
    public:
      fragment_shader(const std::string &file);

      fragment_shader(const fragment_shader &other) = delete;
      fragment_shader &operator=(const fragment_shader &other) = delete;

      virtual ~fragment_shader();
  };
};

#endif
