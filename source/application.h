#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

#include "sys/window.h"
#include "sys/input.h"
#include "sys/system.h"
#include "scene/scene.h"

class Application :
  public sys::RenderListener,
  public sys::ReshapeListener,
  public sys::KeyUpListener,
  public sys::IdleListener {

    public:
      Application(
          sys::System<Application> &system,
          sys::Window &window, sys::Input &input);

      Application(const Application &other) = delete;
      Application &operator=(const Application &other) = delete;

      virtual void onRender();
      virtual void onReshape(const sys::ReshapeEvent &event);
      virtual void onKeyUp(const sys::KeyUpEvent &event);
      virtual void onIdle(const sys::IdleEvent &event);

    private:
      sys::System<Application> &system;
      sys::Window &window;
      sys::Input &input;

      scene::Scene scene;

      unsigned int previousTime;
  };

#endif
