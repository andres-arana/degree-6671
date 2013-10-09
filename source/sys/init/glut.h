#ifndef __SYS_INIT_GLUT_H_INCLUDED__
#define __SYS_INIT_GLUT_H_INCLUDED__

#include "sys/params.h"

namespace sys {
  namespace init {
    class Glut {
      public:
        Glut(const Params &params);

        void mainLoop();

        void leaveMainLoop();

        unsigned int getTime() const;

      private:
        Glut(const Glut &other);
        Glut &operator=(const Glut &other);
    };
  };
};

#endif
