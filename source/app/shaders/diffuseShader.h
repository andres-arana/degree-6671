#ifndef __APP_SHADERS_DIFFUSE_SHADER_H_INCLUDED__
#define __APP_SHADERS_DIFFUSE_SHADER_H_INCLUDED__

#include "sys/shaders/shaderProgram.h"

namespace app {
  namespace shaders {
    class DiffuseShader : public sys::shaders::ShaderProgram {
      public:
        DiffuseShader();

        void bindViewMatrix(const glm::mat4 &viewMatrix) const;

        void bindProjectionMatrix(const glm::mat4 &projMatrix) const;

        void bindLightPosition(const glm::vec4 &lightPos) const;

        void bindLightColor(const glm::vec3 &lightInt) const;

        void bindLightReflectivity(const glm::vec3 &lightInt) const;

        virtual void bindNormalMatrix(const glm::mat3 &normalMatrix) const;

        virtual void bindModelMatrix(const glm::mat4 &modelMatrix) const;

        ~DiffuseShader();
    };
  };
};

#endif
