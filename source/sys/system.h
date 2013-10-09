#ifndef __SYS_SYSTEM_H_INCLUDED__
#define __SYS_SYSTEM_H_INCLUDED__

#include "sys/params.h"
#include "sys/window.h"
#include "sys/input.h"
#include "sys/init/glut.h"
#include "sys/init/info.h"
#include "sys/init/glew.h"

namespace sys {
  template<typename A>
  class System {
    public:
      System(const Params &params);

      void runEventLoop();

      void exitEventLoop();

      unsigned int getTime() const;
    private:
      System(const System &other);
      System &operator=(const System &other);

      init::Glut glut;
      Window window;
      init::Glew glew;
      init::Info info;
      Input input;
      A application;
  };

  template<typename A> System<A>::System(const Params &params) :
    glut(params),
    window(glut, params),
    glew(window, params),
    info(params),
    input(glut, params),
    application(*this, window, input) {

  }

  template<typename A> void System<A>::runEventLoop() {
    glut.mainLoop();
  }

  template<typename A> void System<A>::exitEventLoop() {
    glut.leaveMainLoop();
  }

  template<typename A> unsigned int System<A>::getTime() const {
    return glut.getTime();
  }
};

#endif
