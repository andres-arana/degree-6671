#ifndef __FWK__DISPATCHER_H_INCLUDED__
#define __FWK__DISPATCHER_H_INCLUDED__

namespace fwk {

  class Dispatcher {
    public:

      virtual void onDisplay() = 0;

      virtual ~Dispatcher() {};

  };

};

#endif
