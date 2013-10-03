#ifndef __APP_GEOMETRIES_CUBE_H_INCLUDED__
#define __APP_GEOMETRIES_CUBE_H_INCLUDED__

#include <GL/glew.h>
#include <glm/glm.hpp> 
#include "sys/shaders/shaderProgram.h"

namespace app {
  namespace geometries {

    class Cube {
      public:
        void render(
            const glm::mat4 &modelMatrix, 
            const sys::shaders::ShaderProgram &shader) const;

      private:
        static const GLfloat vertexBuffer[];
        static const GLfloat normalBuffer[];
        static const GLuint indexBuffer[];
        static const unsigned int indexBufferSize;
    };

  };
};

#endif


