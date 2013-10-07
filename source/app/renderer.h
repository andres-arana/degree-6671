#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"
#include "sys/context.h"

#include "app/geometries/register.h"
#include "app/shaders/register.h"

#include "app/scene/scene.h"
#include "app/scene/rotatingCamera.h"
#include "app/scene/FPSCamera.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      void tick(float delta);

      virtual void render(sys::Context &context);

      virtual void resize(int width, int height);

      void toggleCamera();

      app::scene::Camera &getCamera();

    private:
      app::shaders::Register shaders;

      app::geometries::Register geometries;

      app::scene::Scene scene;

      app::scene::RotatingCamera rotatingCamera;

      app::scene::FPSCamera fpsCamera;

      app::scene::Camera *currentCamera;
  };

};

#endif
