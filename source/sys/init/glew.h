#ifndef __SYS_INIT_GLEW_H_INCLUDED__
#define __SYS_INIT_GLEW_H_INCLUDED__

#include "sys/window.h"

namespace sys {
  namespace init {
    class glew {
      public:
        glew(const window &window);

        glew(const glew & other) = delete;
        glew &operator=(const glew &other) = delete;
    };
  };
};

#endif
