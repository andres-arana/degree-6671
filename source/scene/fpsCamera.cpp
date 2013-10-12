#include "scene/fpsCamera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <glm/gtx/constants.hpp> 
#include <cmath>

#define STEP 10.0f

using namespace scene;

FPSCamera::FPSCamera(
    sys::Window &window, 
    sys::Input &input, 
    const glm::vec3 &position,
    const shaders::Cache &shaders) :
  Camera(window, input, shaders),
  position(position),
  rho(-glm::half_pi<float>()),
  forwards(false),
  backwards(false),
  left(false),
  right(false),
  up(false),
  down(false) {

  }

void FPSCamera::doMouseMove(int deltaX, int deltaY) {
  if (deltaX == 0 && deltaY == 0) {
    return;
  }

  if (deltaX) {
    rho += deltaX * 0.001f;
    if (rho > 2 * glm::pi<float>()) {
      rho -= 2 * glm::pi<float>();
    } else if (rho < 0) {
      rho += 2 * glm::pi<float>();
    }
  }

  if (deltaY) {
    theta -= deltaY * 0.001f;
    if (theta >= glm::half_pi<float>()) {
      theta = glm::half_pi<float>();
    } else if (theta <= -glm::half_pi<float>()) {
      theta = -glm::half_pi<float>();
    }
  }
}


void FPSCamera::doKeyUp(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = false;
  } else if (key == 's' || key == 'S') {
    backwards = false;
  } else if (key == 'a' || key == 'A') {
    left = false;
  } else if (key == 'd' || key == 'D') {
    right = false;
  } else if (key == 'q' || key == 'Q') {
    up = false;
  } else if (key == 'e' || key == 'E') {
    down = false;
  }
}

void FPSCamera::doKeyDown(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = true;
  } else if (key == 's' || key == 'S') {
    backwards = true;
  } else if (key == 'a' || key == 'A') {
    left = true;
  } else if (key == 'd' || key == 'D') {
    right = true;
  } else if (key == 'q' || key == 'Q') {
    up = true;
  } else if (key == 'e' || key == 'E') {
    down = true;
  }
}

void FPSCamera::tick(float delta) {
  glm::vec3 forwardVector(
      sin(rho) * cos(theta),
      cos(rho) * cos(theta),
      sin(theta));

  // The cross product between the displacement vector (forward facing) and
  // the up vector is the lateral stepping vector, which should be
  // normalized to ensure proper scaling later
  glm::vec3 lateralVector(
      forwardVector.y,
      -forwardVector.x,
      0);

  if (forwards || backwards || left || right || up || down) {
    glm::vec3 displacement;

    if (forwards) {
      displacement += forwardVector;
    } else if (backwards) {
      displacement -= forwardVector;
    }

    if (left) {
      displacement -= lateralVector;
    } else if (right) {
      displacement += lateralVector;
    }

    if (up) {
      displacement += glm::vec3(0, 0, 1.0f);
    } else if (down) {
      displacement -= glm::vec3(0, 0, 1.0f);
    }

    position += STEP * delta * glm::normalize(displacement);
  }
}

glm::mat4 FPSCamera::getViewMatrix() {
  glm::vec3 target(
      sin(rho) * cos(theta) + position.x,
      cos(rho) * cos(theta) + position.y,
      sin(theta) + position.z);

  return glm::lookAt(
      position,
      target,
      glm::vec3(0.0, 0.0, 1.0));
}


