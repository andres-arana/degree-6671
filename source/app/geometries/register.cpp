#include "app/geometries/register.h"


class Slope : public app::geometries::Function {
  public:
    virtual glm::vec3 apply(float x) const {
      return
        (x * x - 2 * x + 1) * glm::vec3(0, 0, 0) +
        (-2 * x * x + 2 * x) * glm::vec3(0.5f, 3, 0) +
        (x * x) * glm::vec3(4, 0.5f, 0);

    };

    virtual glm::vec3 applyDerivate(float x) const {
      return
        (2 * x - 2) * glm::vec3(0, 0, 0) +
        (-4 * x + 2) * glm::vec3(0.5f, 3, 0) +
        (2 * x) * glm::vec3(4, 0.5f, 0);
    };
};

app::geometries::Register::Register() :
  grid(10),
  sphere(1.0f, 4, 32),
  revolutionSurface(32, 16, Slope()){

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

const app::geometries::RevolutionSurface &app::geometries::Register::getRevolutionSurface() const {
  return revolutionSurface;
}
