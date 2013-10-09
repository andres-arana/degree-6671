#ifndef __SYS_SYSTEM_PARAMS_H_INCLUDED__
#define __SYS_SYSTEM_PARAMS_H_INCLUDED__

#include <string>

namespace sys {
  struct Params {
    int *argc;
    char **argv;
    int width;
    int height;
    std::string title;
  };
};

#endif
