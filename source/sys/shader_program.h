#ifndef __SHADERS_SHADERPROGRAM_H_INCLUDED__
#define __SHADERS_SHADERPROGRAM_H_INCLUDED__

#include "sys/vertex_shader.h"
#include "sys/fragment_shader.h"
#include "sys/shader_param.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>

namespace sys {
  class shader_program {
    public:

      shader_program(const shader_program &other) = delete;
      shader_program &operator=(const shader_program &other) = delete;

      void use() const;

      virtual void bind_model_matrix(const glm::mat4 &model_matrix) const = 0;

      virtual ~shader_program();

    protected:
      shader_program(
          vertex_shader *vertex_shader, 
          fragment_shader *fragment_shader);

      shader_param get_uniform_param(const char* name) const;

    private:
      std::auto_ptr<vertex_shader> vertex;
      std::auto_ptr<fragment_shader> fragment;
      GLuint handle;
  };
};

#endif

