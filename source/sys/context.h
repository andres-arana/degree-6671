#ifndef __SYS_CONTEXT_H_INCLUDED__
#define __SYS_CONTEXT_H_INCLUDED__

#include "sys/application.h"
#include "sys/window.h"
#include "sys/glew.h"
#include "sys/input/input.h"

namespace sys {
  class System;

  class Context {
    public:
      void runEventLoop();

      void exitEventLoop();

      Application &getApplication();

      Window &getWindow();

      Glew &getGlew();

      input::Input &getInput();

    private:
      Application &application;
      Window window;
      Glew glew;
      input::Input input;

      friend class System;

      Context(Application &application);
      Context(const Context &context);
      Context &operator=(const Context &context);
  };

};

#endif
