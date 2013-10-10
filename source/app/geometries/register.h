#ifndef __APP_GEOMETRIES_REGISTER_H_INCLUDED__
#define __APP_GEOMETRIES_REGISTER_H_INCLUDED__

#include "app/geometries/grid.h"
#include "app/geometries/revolutionSurface.h"

namespace app {
  namespace geometries {
    class Register {
      public:
        Register();

        const Grid &getGrid() const;

        const RevolutionSurface &getRevolutionSurface() const;

        const RevolutionSurface &getLightBulb() const;

      private:
        Grid grid;
        RevolutionSurface revolutionSurface;
        RevolutionSurface lightBulb;
    };
  };
};

#endif
