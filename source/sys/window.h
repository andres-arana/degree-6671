#ifndef __SYS_WINDOW_H_INCLUDED__
#define __SYS_WINDOW_H_INCLUDED__

#include "sys/params.h"
#include "sys/init/glut.h"

namespace sys {
  class Window {
    public:
      Window(const init::Glut &glut, const Params &params);

      Window(const Window &other) = delete;
      Window &operator=(const Window &other) = delete;

      void toggleFullScreen();

      void hideCursor();

      void showCursor();

      void swapBuffers();

      float getAspectRatio() const;

      int getWidth() const;

      int getHeight() const;

      void setCursorPosition(int x, int y);
    private:

      unsigned int id;
  };
};

#endif
