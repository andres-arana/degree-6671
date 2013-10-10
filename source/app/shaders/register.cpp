#include "app/shaders/register.h"

using namespace app::shaders;


Register::Register() {

}

const DiffuseShader &Register::getDiffuseShader() const {
  return diffuseShader;
}
