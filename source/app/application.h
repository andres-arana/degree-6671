#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

#include "sys/application.h"
#include "app/renderer.h"
#include "app/dispatcher.h"

namespace app {

  class Application : public sys::Application {
    public:
      Application();

      virtual unsigned int getWidth();

      virtual unsigned int getHeight();

      virtual unsigned int getPositionX();

      virtual unsigned int getPositionY();

      virtual const char* getTitle();

      virtual sys::Renderer &getRenderer();

      virtual sys::Dispatcher &getDispatcher();

      virtual ~Application();

    private:
      Renderer *renderer;
      Dispatcher *dispatcher;
  };

};

#endif
