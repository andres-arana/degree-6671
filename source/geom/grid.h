#ifndef __GEOM_GRID_H_INCLUDED__
#define __GEOM_GRID_H_INCLUDED__

#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <vector>
#include "sys/shaderProgram.h"

namespace geom {
  class Grid {
    public:
      Grid(int size);

      Grid(const Grid &other) = delete;
      Grid &operator=(const Grid &other) = delete;

      void render(
          const glm::mat4 &modelMatrix,
          const sys::ShaderProgram &shader) const;

    private:
      std::vector<GLfloat> vertexBuffer;
      std::vector<GLuint> indexBuffer;

      unsigned int assignVertex(unsigned int offset, GLfloat x, GLfloat y, GLfloat z);
  };
};

#endif


