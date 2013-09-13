#ifndef __SYS_SHADERS_SHADERPROGRAM_H_INCLUDED__
#define __SYS_SHADERS_SHADERPROGRAM_H_INCLUDED__

#include "sys/shaders/shader.h"
#include "sys/shaders/shaderParam.h"

namespace sys {
  namespace shaders {

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
};

#endif

