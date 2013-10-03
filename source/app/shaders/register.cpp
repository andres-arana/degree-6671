#include "app/shaders/register.h"


app::shaders::Register::Register() {

}

const app::shaders::DiffuseShader &app::shaders::Register::getDiffuseShader() const {
  return diffuseShader;
}
