#ifndef __SYS_INIT_INFO_H_INCLUDED_
#define __SYS_INIT_INFO_H_INCLUDED_

namespace sys {
  namespace init {
    class Info {
      public:
        Info();

        Info(const Info &other) = delete;
        Info &operator=(const Info &other) = delete;
    };
  };
};

#endif
