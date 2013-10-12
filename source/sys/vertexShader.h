#ifndef __SHADERS_VERTEX_SHADER_H_INCLUDED__
#define __SHADERS_VERTEX_SHADER_H_INCLUDED__

#include "sys/shader.h"

namespace sys {
  class VertexShader : public Shader {
    public:
      VertexShader(const std::string &file);

      VertexShader(const VertexShader &other) = delete;
      VertexShader &operator=(const VertexShader &other) = delete;

      virtual ~VertexShader();
  };
};

#endif
