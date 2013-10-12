#ifndef __SHADERS_BASIC_H_INCLUDED__
#define __SHADERS_BASIC_H_INCLUDED__

#include "sys/shader_program.h"

namespace shaders {
  class basic : public sys::shader_program {
    public:
      basic();

      basic(const basic &other) = delete;
      basic &operator=(const basic &other) = delete;

      void bind_view_matrix(const glm::mat4 &view_matrix) const;

      void bind_projection_matrix(const glm::mat4 &proj_matrix) const;

      void bind_light_position(const glm::vec4 &light_pos) const;

      void bind_diffuse_intensity(const glm::vec3 &light_int) const;

      void bind_diffuse_reflectivity(const glm::vec3 &light_int) const;

      void bind_ambient_intensity(const glm::vec3 &light_int) const;

      void bind_ambient_reflectivity(const glm::vec3 &light_int) const;

      void bind_specular_intensity(const glm::vec3 &light) const;

      void bind_specular_reflectivity(const glm::vec3 &light) const;

      void bind_specular_shininess(float shininess) const;

      virtual void bind_model_matrix(const glm::mat4 &model_matrix) const;
  };
};

#endif
