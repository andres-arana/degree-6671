#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"
#include "sys/context.h"
#include "sys/shaders/shader.h"
#include "sys/shaders/shaderProgram.h"
#include "app/graphics/grid.h"
#include "app/graphics/cube.h"
#include "app/graphics/sphere.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      virtual void render(sys::Context &context);

      virtual void resize(int width, int height);

    private:
      sys::shaders::Shader vertexShader;
      sys::shaders::Shader fragmentShader;
      sys::shaders::ShaderProgram program;

      graphics::Grid grid;
      graphics::Cube cube;
      graphics::Sphere sphere;

      void setupView();
      void setupProjection(float aspectRatio);
      void setupLights();
      void setupLightColors(float red, float green, float blue);
  };

};

#endif
