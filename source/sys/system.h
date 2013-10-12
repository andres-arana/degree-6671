#ifndef __SYS_SYSTEM_H_INCLUDED__
#define __SYS_SYSTEM_H_INCLUDED__

#include "sys/params.h"
#include "sys/window.h"
#include "sys/input.h"
#include "sys/init/glut.h"
#include "sys/init/info.h"
#include "sys/init/glew.h"

namespace sys {
  template<typename A> class system {
    public:
      system(const params &params);

      system(const system &other) = delete;
      system &operator=(const system &other) = delete;

      void run_event_loop();

      void exit_event_loop();

      unsigned int get_time() const;
    private:

      init::glut glut;
      sys::window window;
      init::glew glew;
      init::info info;
      sys::input input;
      A application;
  };

  template<typename A> system<A>::system(const params &params) :
    glut(params),
    window(glut, params),
    glew(window),
    info(),
    input(glut),
    application(*this, window, input) {

    }

  template<typename A> void system<A>::run_event_loop() {
    glut.main_loop();
  }

  template<typename A> void system<A>::exit_event_loop() {
    glut.leave_main_loop();
  }

  template<typename A> unsigned int system<A>::get_time() const {
    return glut.get_time();
  }
};

#endif
