#ifndef __FWK__WINDOW_H_INCLUDED__
#define __FWK__WINDOW_H_INCLUDED__

#include "fwk/dispatcher.h"

namespace fwk {

  class Window {
    public:
      Window(Dispatcher &dispatcher, const char* title, int width, int height);

      bool is(int id) const;

      Dispatcher &dispatch();

    private:
      Dispatcher &dispatcher;
      int id;

      void initializeGLEW();
  };

};

#endif
