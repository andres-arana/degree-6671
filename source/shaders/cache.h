#ifndef __SHADERS_CACHE_H_INCLUDED__
#define __SHADERS_CACHE_H_INCLUDED__

#include "shaders/basic.h"

namespace shaders {
  struct cache {
    cache();

    cache(const cache &other) = delete;
    cache &operator=(const cache &other) = delete;

    shaders::basic basic;
  };
};

#endif
