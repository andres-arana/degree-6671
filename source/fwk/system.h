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

      static void onClose();
      static void onReshape(int width, int height);
      static void onDisplay();
      static void onMouse(int button, int updown, int x, int y);
      static void onMouseWheel(int whellNumber, int direction, int x, int y);
      static void onMouseMotion(int x, int y);
      static void onSpecialKeyUp(int key, int x, int y);
      static void onKeyUp(unsigned char key, int x, int y);
      static void onSpecialKeyDown(int key, int x, int y);
      static void onKeyDown(unsigned char key, int x, int y);
      static void onIdle();
  };

};

#endif
