#ifndef __APP_SHADERPROGRAM_H_INCLUDED__
#define __APP_SHADERPROGRAM_H_INCLUDED__

#include "app/shader.h"

namespace app {

  class ShaderProgram {
    public:
      ShaderProgram(
          const Shader &vertexShader, 
          const Shader &fragmentShader);

      void use() const;

      virtual ~ShaderProgram() {};

    private:
      GLuint handle;
  };

};

#endif

