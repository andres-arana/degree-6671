#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

#include "sys/window.h"
#include "sys/input.h"
#include "sys/system.h"
#include "app/scene/scene.h"

namespace app {

  class Application :
    public sys::RenderListener,
    public sys::ReshapeListener,
    public sys::KeyUpListener,
    public sys::IdleListener {

    public:
      Application(sys::System<Application> &system, sys::Window &window, sys::Input &input);

      virtual void onRender();
      virtual void onReshape(const sys::ReshapeEvent &event);
      virtual void onKeyUp(const sys::KeyUpEvent &event);
      virtual void onIdle(const sys::IdleEvent &event);

    private:
      Application(const Application &other);
      Application &operator=(const Application &other);

      sys::System<Application> &system;
      sys::Window &window;
      sys::Input &input;

      app::shaders::Register shaders;
      app::geometries::Register geometries;

      app::scene::Scene scene;

      unsigned int previousTime;
  };

};

#endif
