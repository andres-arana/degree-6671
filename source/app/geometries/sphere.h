#ifndef __APP_GEOMETRIES_SPHERE_H_INCLUDED__
#define __APP_GEOMETRIES_SPHERE_H_INCLUDED__

#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <vector>
#include "sys/shaders/shaderProgram.h"

namespace app {
  namespace geometries {

    class Sphere {
      public:
        Sphere(
            float radius,
            unsigned int loops,
            unsigned int segmentsPerLoop);

        void render(
            const glm::mat4 &modelMatrix, 
            const sys::shaders::ShaderProgram &program) const;

      private:
        std::vector<GLfloat> vertexBuffer;
        std::vector<GLuint> indexBuffer;

        static const float PI;
    };

  };
};

#endif


