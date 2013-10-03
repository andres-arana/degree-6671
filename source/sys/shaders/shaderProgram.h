#ifndef __SYS_SHADERS_SHADERPROGRAM_H_INCLUDED__
#define __SYS_SHADERS_SHADERPROGRAM_H_INCLUDED__

#include "sys/shaders/vertexShader.h"
#include "sys/shaders/fragmentShader.h"
#include "sys/shaders/shaderParam.h"
#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <memory>

namespace sys {
  namespace shaders {

    class ShaderProgram {
      public:
        void use() const;

        virtual void bindNormalMatrix(const glm::mat3 &normalMatrix) const = 0;

        virtual void bindModelMatrix(const glm::mat4 &modelMatrix) const = 0;

        virtual ~ShaderProgram();

      protected:
        ShaderProgram(
            VertexShader *vertexShader, 
            FragmentShader *fragmentShader);

        ShaderParam getUniformParam(const char* name) const;

      private:
        std::auto_ptr<VertexShader> vertexShader;
        std::auto_ptr<FragmentShader> fragmentShader;
        GLuint handle;
    };

  };
};

#endif

