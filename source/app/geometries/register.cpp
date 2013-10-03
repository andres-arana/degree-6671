#include "app/geometries/register.h"


app::geometries::Register::Register() :
  grid(10),
  sphere(1.0f, 32, 32) {

}

const app::geometries::Cube &app::geometries::Register::getCube() const {
  return cube;
}

const app::geometries::Grid &app::geometries::Register::getGrid() const {
  return grid;
}

const app::geometries::Sphere &app::geometries::Register::getSphere() const {
  return sphere;
}
