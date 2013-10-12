#ifndef __SHADERS_BASIC_H_INCLUDED__
#define __SHADERS_BASIC_H_INCLUDED__

#include "sys/shaderProgram.h"

namespace shaders {
  class Basic : public sys::ShaderProgram {
    public:
      Basic();

      Basic(const Basic &other) = delete;
      Basic &operator=(const Basic &other) = delete;

      void bindViewMatrix(const glm::mat4 &viewMatrix) const;

      void bindProjectionMatrix(const glm::mat4 &projMatrix) const;

      void bindLightPosition(const glm::vec4 &lightPos) const;

      void bindDiffuseIntensity(const glm::vec3 &lightInt) const;

      void bindDiffuseReflectivity(const glm::vec3 &lightInt) const;

      void bindAmbientIntensity(const glm::vec3 &lightInt) const;

      void bindAmbientReflectivity(const glm::vec3 &lightInt) const;

      virtual void bindModelMatrix(const glm::mat4 &modelMatrix) const;
  };
};

#endif
