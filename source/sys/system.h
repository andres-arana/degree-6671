#ifndef __FWK__SYSTEM_H_INCLUDED__
#define __FWK__SYSTEM_H_INCLUDED__

#include "sys/context.h"
#include "sys/application.h"

namespace sys {

  class System {
    public:
      System(int argc, char **argv);

      Context createContext(sys::Application &application);
  };

};

#endif
