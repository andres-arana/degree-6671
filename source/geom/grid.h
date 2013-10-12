#ifndef __GEOM_GRID_H_INCLUDED__
#define __GEOM_GRID_H_INCLUDED__

#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <vector>
#include "sys/shader_program.h"

namespace geom {
  class grid {
    public:
      grid(int size);

      grid(const grid &other) = delete;
      grid &operator=(const grid &other) = delete;

      void render(
          const glm::mat4 &model_matrix,
          const sys::shader_program &shader) const;

    private:
      std::vector<GLfloat> vertex_buffer;
      std::vector<GLuint> index_buffer;

      unsigned int assign_vertex(unsigned int offset, GLfloat x, GLfloat y, GLfloat z);
  };
};

#endif


