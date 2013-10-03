#ifndef __SYS_SHADERS_VERTEX_SHADER_H_INCLUDED__
#define __SYS_SHADERS_VERTEX_SHADER_H_INCLUDED__

#include "sys/shaders/shader.h"

namespace sys {
  namespace shaders {
    class VertexShader : public Shader {
      public:
        VertexShader(const std::string &file);

        virtual ~VertexShader();
    
    };
  };
};

#endif
