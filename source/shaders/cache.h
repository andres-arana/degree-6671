#ifndef __SHADERS_CACHE_H_INCLUDED__
#define __SHADERS_CACHE_H_INCLUDED__

#include "shaders/basic.h"

namespace shaders {
  struct Cache {
    Cache();

    Cache(const Cache &other) = delete;
    Cache &operator=(const Cache &other) = delete;

    Basic basic;
  };
};

#endif
