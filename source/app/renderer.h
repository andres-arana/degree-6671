#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"
#include "sys/context.h"

#include "app/geometries/register.h"
#include "app/shaders/register.h"

#include "app/scene/scene.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      virtual void render(sys::Context &context);

      virtual void resize(int width, int height);

    private:
      app::shaders::Register shaderRegister;

      app::geometries::Register geometryRegister;

      app::scene::Scene scene;

  };

};

#endif
