#ifndef __SYS_APPLICATION_H_INCLUDED__
#define __SYS_APPLICATION_H_INCLUDED__

#include "sys/input/dispatcher.h"

namespace sys {
  class Context;

  class Renderer {
    public:
      virtual void render(Context &context) = 0;

      virtual ~Renderer() {};
  };

  class Application {
    public:
      virtual unsigned int getWidth() = 0;

      virtual unsigned int getHeight() = 0;

      virtual unsigned int getPositionX() = 0;

      virtual unsigned int getPositionY() = 0;

      virtual const char* getTitle() = 0;

      virtual Renderer &getRenderer() = 0;

      virtual sys::input::Dispatcher &getDispatcher() = 0;

      virtual ~Application() {};

  };

};

#endif
