#ifndef __APP_GEOMETRIES_CUADRATIC_BEZIER_H_INCLUDE__
#define __APP_GEOMETRIES_CUADRATIC_BEZIER_H_INCLUDE__

#include "app/geometries/revolutionSurface.h"

namespace app {
  namespace geometries {
    class CuadraticBezier : public Function {
      public:
        CuadraticBezier(const glm::vec3 &p0, const glm::vec3 &p1, const glm::vec3 &p2);

        virtual glm::vec3 apply(float x) const;

        virtual glm::vec3 applyDerivate(float x) const;

      private:
        glm::vec3 p0;
        glm::vec3 p1;
        glm::vec3 p2;
    };
  };
};

#endif
