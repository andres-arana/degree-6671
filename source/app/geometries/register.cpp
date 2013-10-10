#include "app/geometries/register.h"
#include "app/geometries/cuadraticBezier.h"

using namespace app::geometries;

static CuadraticBezier bodyBezier(glm::vec3(0, 0, 0), glm::vec3(0.5f, 3, 0), glm::vec3(4, 0.5f, 0));
static CuadraticBezier lightbulbBezier(glm::vec3(0, 0, 0), glm::vec3(0.01f, 0.5f, 0), glm::vec3(0.8f, 0.1f, 0));

Register::Register() :
  grid(10),
  revolutionSurface(32, 16, bodyBezier),
  lightBulb(16, 8, lightbulbBezier){

  }

const Grid &Register::getGrid() const {
  return grid;
}

const RevolutionSurface &Register::getRevolutionSurface() const {
  return revolutionSurface;
}

const RevolutionSurface &Register::getLightBulb() const {
  return lightBulb;
}
