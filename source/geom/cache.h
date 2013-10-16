#ifndef __GEOM_CACHE_H_INCLUDED__
#define __GEOM_CACHE_H_INCLUDED__

#include "geom/grid.h"
#include "geom/revolution_surface.h"
#include "geom/surface_patch.h"

namespace geom {
  struct cache {
      cache();

      cache(const cache &other) = delete;
      cache &operator=(const cache &other) = delete;

      geom::grid grid;

      geom::surface_patch crab_body;
      geom::revolution_surface crab_leg_root;
      geom::revolution_surface crab_leg_section;
      geom::revolution_surface crab_leg_finisher;
      geom::revolution_surface crab_eye_leader;
      geom::revolution_surface crab_eye;
  };
};

#endif
