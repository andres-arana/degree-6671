#include "app/scene/rotatingCamera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <glm/gtx/constants.hpp> 
#include <cmath>

#define STEP 10.0f

using namespace app;
using namespace app::scene;
using namespace sys;

RotatingCamera::RotatingCamera(
    Window &window,
    Input &input,
    const glm::vec3 &center,
    float distance,
    const shaders::Register &shaders) :
  Camera(window, input, shaders),
  center(center),
  distance(distance),
  rho(glm::half_pi<float>()),
  forwards(false),
  backwards(false) {

  }

void RotatingCamera::doMouseMove(int deltaX, int deltaY) {
  if (deltaX == 0 && deltaY == 0) {
    return;
  }

  if (deltaX) {
    rho += deltaX * 0.005f;
    if (rho > 2 * glm::pi<float>()) {
      rho -= 2 * glm::pi<float>();
    } else if (rho < 0) {
      rho += 2 * glm::pi<float>();
    }
  }

  if (deltaY) {
    theta += deltaY * 0.005f;
    if (theta >= glm::half_pi<float>()) {
      theta = glm::half_pi<float>();
    } else if (theta <= -glm::half_pi<float>()) {
      theta = -glm::half_pi<float>();
    }
  }
}


void RotatingCamera::doKeyUp(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = false;
  }

  if(key == 's' || key == 'S') {
    backwards = false;
  }
}

void RotatingCamera::doKeyDown(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = true;
  }

  if(key == 's' || key == 'S') {
    backwards = true;
  }

}

void RotatingCamera::tick(float delta) {
  if (forwards) {
    distance -= STEP * delta;
  }

  if (backwards) {
    distance += STEP * delta;
  }
}

glm::mat4 RotatingCamera::getViewMatrix() {
  glm::vec3 position(
      distance * sin(rho) * cos(theta) + center.x,
      distance * cos(rho) * cos(theta) + center.y,
      distance * sin(theta) + center.z);

  return glm::lookAt(
        position,
        center,
        glm::vec3(0.0, 0.0, 1.0));
}
