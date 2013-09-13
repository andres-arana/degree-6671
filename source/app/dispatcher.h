#ifndef __APP_DISPATCHER_H_INCLUDED__
#define __APP_DISPATCHER_H_INCLUDED__

#include "sys/application.h"

namespace app {

  class Dispatcher : public sys::Dispatcher {
    public:
      virtual void onKeyUp(unsigned char key, int x, int y);
  };

};

#endif
