#ifndef __SYS_INIT_GLEW_H_INCLUDED__
#define __SYS_INIT_GLEW_H_INCLUDED__

#include "sys/params.h"
#include "sys/window.h"

namespace sys {
  namespace init {
    class Glew {
      public:
        Glew(const Window &window, const Params &params);

      private:
        Glew(const Glew & other);
        Glew &operator=(const Glew &other);
    };
  };
};

#endif
