#ifndef __SYS_INIT_GLUT_H_INCLUDED__
#define __SYS_INIT_GLUT_H_INCLUDED__

#include "sys/params.h"

namespace sys {
  namespace init {
    class glut {
      public:
        glut(const params &params);

        glut(const glut &other) = delete;
        glut &operator=(const glut &other) = delete;

        void main_loop();

        void leave_main_loop();

        unsigned int get_time() const;
    };
  };
};

#endif
