#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"
#include "app/shader.h"
#include "app/shaderProgram.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      virtual void render();

    private:
      Shader vertexShader;
      Shader fragmentShader;
      ShaderProgram program;
  };

};

#endif
