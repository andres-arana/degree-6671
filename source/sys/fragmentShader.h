#ifndef __SHADERS_FRAGMENT_SHADER_H_INCLUDED__
#define __SHADERS_FRAGMENT_SHADER_H_INCLUDED__

#include "sys/shader.h"

namespace sys {
  class FragmentShader : public Shader {
    public:
      FragmentShader(const std::string &file);

      FragmentShader(const FragmentShader &other) = delete;
      FragmentShader &operator=(const FragmentShader &other) = delete;

      virtual ~FragmentShader();
  };
};

#endif
