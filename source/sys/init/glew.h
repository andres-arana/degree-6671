#ifndef __SYS_INIT_GLEW_H_INCLUDED__
#define __SYS_INIT_GLEW_H_INCLUDED__

#include "sys/window.h"

namespace sys {
  namespace init {
    class Glew {
      public:
        Glew(const Window &window);

        Glew(const Glew & other) = delete;
        Glew &operator=(const Glew &other) = delete;
    };
  };
};

#endif
