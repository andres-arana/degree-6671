#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"
#include "sys/context.h"
#include "app/shader.h"
#include "app/shaderProgram.h"
#include "app/graphics/grid.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      virtual void render(sys::Context &context);

    private:
      Shader vertexShader;
      Shader fragmentShader;
      ShaderProgram program;

      graphics::Grid grid;

      void setupView();
      void setupProjection(float aspectRatio);
      void setupLights();
      void setupLightColors(float red, float green, float blue);
  };

};

#endif
