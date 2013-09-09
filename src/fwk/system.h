#ifndef __FWK__SYSTEM_H_INCLUDED__
#define __FWK__SYSTEM_H_INCLUDED__

#include "fwk/window.h"
#include <list>

namespace fwk {

  class System {
    public:
      System(int argc, char **argv);

      Window &createWindow(Dispatcher& dispatcher, const char *title, int width, int height);

      void runEventLoop();

      ~System();
    private:
      typedef std::list<Window*> Windows;
      static Windows windows;

      static Windows::iterator lookupCurrentWindow();

      static void onDisplay();
  };

};

#endif
