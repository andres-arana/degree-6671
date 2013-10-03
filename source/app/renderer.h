#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"
#include "sys/context.h"
#include "sys/shaders/fragmentShader.h"
#include "sys/shaders/vertexShader.h"
#include "sys/shaders/shaderProgram.h"
#include "app/geometries/grid.h"
#include "app/geometries/cube.h"
#include "app/geometries/sphere.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      virtual void render(sys::Context &context);

      virtual void resize(int width, int height);

    private:
      sys::shaders::VertexShader vertexShader;
      sys::shaders::FragmentShader fragmentShader;
      sys::shaders::ShaderProgram program;

      geometries::Grid grid;
      geometries::Cube cube;
      geometries::Sphere sphere;

      void setupView();
      void setupProjection(float aspectRatio);
      void setupLights();
      void setupLightColors(float red, float green, float blue);

      void renderGrid(const glm::mat4 &modelMatrix);
      void renderArmSection(const glm::mat4 &modelMatrix);
      void renderArm(const glm::mat4 &modelMatrix);
  };

};

#endif
