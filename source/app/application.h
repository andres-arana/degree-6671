#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

#include "sys/application.h"
#include "app/renderer.h"
#include "app/dispatcher.h"
#include <memory>

namespace app {

  class Application : public sys::Application {
    public:
      Application();

      virtual unsigned int getWidth();

      virtual unsigned int getHeight();

      virtual unsigned int getPositionX();

      virtual unsigned int getPositionY();

      virtual const char* getTitle();

      virtual void configureWindow(sys::Window& window);

      virtual sys::Renderer &getRenderer();

      virtual sys::input::Dispatcher &getDispatcher();

      app::scene::Camera &getCamera();

      void toggleCamera();

    private:
      std::auto_ptr<Renderer>   renderer;
      std::auto_ptr<Dispatcher> dispatcher;

      Application(const Application &other);
      Application &operator=(const Application &other);
  };

};

#endif
