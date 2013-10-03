#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"
#include "sys/context.h"
#include "app/shaders/diffuseShader.h"
#include "app/geometries/register.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      virtual void render(sys::Context &context);

      virtual void resize(int width, int height);

    private:
      app::shaders::DiffuseShader diffuseShader;

      app::geometries::Register geometryRegister;

      void renderGrid(const glm::mat4 &modelMatrix);
      void renderArmSection(const glm::mat4 &modelMatrix);
      void renderArm(const glm::mat4 &modelMatrix);
  };

};

#endif
