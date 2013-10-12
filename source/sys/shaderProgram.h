#ifndef __SHADERS_SHADERPROGRAM_H_INCLUDED__
#define __SHADERS_SHADERPROGRAM_H_INCLUDED__

#include "sys/vertexShader.h"
#include "sys/fragmentShader.h"
#include "sys/shaderParam.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>

namespace sys {
  class ShaderProgram {
    public:

      ShaderProgram(const ShaderProgram &other) = delete;
      ShaderProgram &operator=(const ShaderProgram &other) = delete;

      void use() const;

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

#endif

