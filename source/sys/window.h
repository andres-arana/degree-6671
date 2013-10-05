#ifndef __SYS_WINDOW_H_INCLUDED__
#define __SYS_WINDOW_H_INCLUDED__

#include "sys/application.h"

namespace sys {
  class Context;

  class Window {
    public:
      bool isIdentifiedBy(unsigned int windowId) const;

      void toggleFullScreen();

      void hideCursor();

      void showCursor();

      void swapBuffers();

      float getAspectRatio() const;

      int getWidth() const;

      int getHeight() const;

      void setCursorPosition(int x, int y);
    private:
      friend class Context;

      Window(Context &context);
      Window(const Window &other);
      Window &operator=(const Window &other);

      unsigned int id;
  };

};

#endif
