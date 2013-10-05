#include "app/scene/rotatingCamera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <cmath>

#define PI 3.1415f

app::scene::RotatingCamera::RotatingCamera(
    const glm::vec3 &center,
    float distance,
    const app::shaders::Register &shaders) :
  shaders(shaders),
  center(center),
  distance(distance) {

  }

void app::scene::RotatingCamera::move(int deltaX, int deltaY) {
  if (deltaX == 0 && deltaY == 0) {
    return;
  }

  if (deltaX) {
    rho += deltaX * 0.005f;
    if (rho > 2 * PI) {
      rho -= 2 * PI;
    } else if (rho < 0) {
      rho += 2 * PI;
    }
  }

  if (deltaY) {
    theta += deltaY * 0.005f;
    if (theta >= PI / 2) {
      theta = PI / 2;
    } else if (theta <= -PI / 2) {
      theta = -PI / 2;
    }
  }
}

void app::scene::RotatingCamera::use() {
  glm::vec3 position(
      distance * sin(rho) * cos(theta),
      distance * cos(rho) * cos(theta),
      distance * sin(theta));

  shaders.getDiffuseShader().bindViewMatrix(
      glm::lookAt(
        position,
        center,
        glm::vec3(0.0, 0.0, 1.0)));
}
