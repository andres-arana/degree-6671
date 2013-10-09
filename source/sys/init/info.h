#ifndef __SYS_INIT_INFO_H_INCLUDED_
#define __SYS_INIT_INFO_H_INCLUDED_

#include "sys/params.h"

namespace sys {
  namespace init {
    class Info {
      public:
        Info(const Params &params);

      private:
        Info(const Info &other);
        Info &operator=(const Info &other);
    };
  };
};

#endif
