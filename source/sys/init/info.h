#ifndef __SYS_INIT_INFO_H_INCLUDED_
#define __SYS_INIT_INFO_H_INCLUDED_

namespace sys {
  namespace init {
    class info {
      public:
        info();

        info(const info &other) = delete;
        info &operator=(const info &other) = delete;
    };
  };
};

#endif
