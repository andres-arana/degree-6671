#ifndef __APP_GEOMETRIES_REGISTER_H_INCLUDED__
#define __APP_GEOMETRIES_REGISTER_H_INCLUDED__

#include "app/geometries/grid.h"
#include "app/geometries/cube.h"
#include "app/geometries/sphere.h"

namespace app {
  namespace geometries {
    class Register {
      public:
        Register();

        const Cube &getCube() const;

        const Grid &getGrid() const;

        const Sphere &getSphere() const;

      private:
        Cube cube;
        Grid grid;
        Sphere sphere;
    };
  };
};

#endif
