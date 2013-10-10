#include "app/geometries/register.h"
#include "app/geometries/cuadraticBezier.h"

app::geometries::Register::Register() :
  grid(10),
  revolutionSurface(32, 16, app::geometries::CuadraticBezier(glm::vec3(0, 0, 0), glm::vec3(0.5f, 3, 0), glm::vec3(4, 0.5f, 0))),
  lightBulb(16, 8, app::geometries::CuadraticBezier(glm::vec3(0, 0, 0), glm::vec3(0.01f, 0.5f, 0), glm::vec3(0.8f, 0.1f, 0))){

  }

const app::geometries::Grid &app::geometries::Register::getGrid() const {
  return grid;
}

const app::geometries::RevolutionSurface &app::geometries::Register::getRevolutionSurface() const {
  return revolutionSurface;
}

const app::geometries::RevolutionSurface &app::geometries::Register::getLightBulb() const {
  return lightBulb;
}
