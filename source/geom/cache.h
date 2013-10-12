#ifndef __GEOM_CACHE_H_INCLUDED__
#define __GEOM_CACHE_H_INCLUDED__

#include "geom/grid.h"
#include "geom/revolutionSurface.h"

namespace geom {
  struct Cache {
      Cache();

      Cache(const Cache &other) = delete;
      Cache &operator=(const Cache &other) = delete;

      Grid grid;

      RevolutionSurface crabBody;
  };
};

#endif
