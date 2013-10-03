#ifndef __SYS_SHADERS_FRAGMENT_SHADER_H_INCLUDED__
#define __SYS_SHADERS_FRAGMENT_SHADER_H_INCLUDED__

#include "sys/shaders/shader.h"

namespace sys {
  namespace shaders {
    class FragmentShader : public Shader {
      public:
        FragmentShader(const std::string &file);

        virtual ~FragmentShader();
    };
  };
};

#endif
