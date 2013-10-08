#include "app/scene/rotatingCamera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <cmath>

#define PI 3.1415f
#define STEP 10.0f

app::scene::RotatingCamera::RotatingCamera(
    const glm::vec3 &center,
    float distance,
    const app::shaders::Register &shaders) :
  shaders(shaders),
  center(center),
  distance(distance),
  rho(PI / 2){

  }

void app::scene::RotatingCamera::onMouseMove(int deltaX, int deltaY) {
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


void app::scene::RotatingCamera::onKeyUp(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = false;
  }

  if(key == 's' || key == 'S') {
    backwards = false;
  }
}

void app::scene::RotatingCamera::onKeyDown(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = true;
  }

  if(key == 's' || key == 'S') {
    backwards = true;
  }

}

void app::scene::RotatingCamera::tick(float delta) {
  if (forwards) {
    distance -= STEP * delta;
  }

  if (backwards) {
    distance += STEP * delta;
  }
}

void app::scene::RotatingCamera::use() {
  glm::vec3 position(
      distance * sin(rho) * cos(theta) + center.x,
      distance * cos(rho) * cos(theta) + center.y,
      distance * sin(theta) + center.z);

  shaders.getDiffuseShader().bindViewMatrix(
      glm::lookAt(
        position,
        center,
        glm::vec3(0.0, 0.0, 1.0)));
}
