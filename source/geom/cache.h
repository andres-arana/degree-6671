#ifndef __GEOM_CACHE_H_INCLUDED__
#define __GEOM_CACHE_H_INCLUDED__

#include "geom/grid.h"
#include "geom/revolution_surface.h"

namespace geom {
  struct cache {
      cache();

      cache(const cache &other) = delete;
      cache &operator=(const cache &other) = delete;

      geom::grid grid;

      geom::revolution_surface crab_body;
      geom::revolution_surface crab_leg_section;
  };
};

#endif
