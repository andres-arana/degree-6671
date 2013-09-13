#ifndef __APP_SHADERPROGRAM_H_INCLUDED__
#define __APP_SHADERPROGRAM_H_INCLUDED__

#include "app/shader.h"
#include "app/shaderParam.h"

namespace app {

  class ShaderProgram {
    public:
      ShaderProgram(
          const Shader &vertexShader, 
          const Shader &fragmentShader);

      void use() const;

      ShaderParam getUniformParam(const char* name) const;

      virtual ~ShaderProgram() {};

    private:
      GLuint handle;
  };

};

#endif

