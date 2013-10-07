#include "app/scene/FPSCamera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <cmath>

#define PI 3.1415f
#define STEP 10.0f

app::scene::FPSCamera::FPSCamera(
    const glm::vec3 &position,
    const app::shaders::Register &shaders) :
  shaders(shaders),
  position(position) {

  }

void app::scene::FPSCamera::onMouseMove(int deltaX, int deltaY) {
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
    theta -= deltaY * 0.005f;
    if (theta >= PI / 2) {
      theta = PI / 2;
    } else if (theta <= -PI / 2) {
      theta = -PI / 2;
    }
  }
}


void app::scene::FPSCamera::onKeyUp(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = false;
  } else if (key == 's' || key == 'S') {
    backwards = false;
  } else if (key == 'a' || key == 'A') {
    left = false;
  } else if (key == 'd' || key == 'D') {
    right = false;
  }
}

void app::scene::FPSCamera::onKeyDown(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = true;
  } else if (key == 's' || key == 'S') {
    backwards = true;
  } else if (key == 'a' || key == 'A') {
    left = true;
  } else if (key == 'd' || key == 'D') {
    right = true;
  }
}

void app::scene::FPSCamera::tick(float delta) {
  if (forwards || backwards || left || right) {
    glm::vec3 displacement(
        sin(rho) * cos(theta),
        cos(rho) * cos(theta),
        sin(theta));

    if (forwards) {

      position += STEP * displacement * delta;

    } else if (backwards) {

      position -= STEP * displacement * delta;

    } else if (left || right) {

      // The cross product between the displacement vector (forward facing) and
      // the up vector is the lateral stepping vector, which should be
      // normalized to ensure proper scaling later
      glm::vec3 lateral = glm::normalize(glm::vec3(
            displacement.y,
            -displacement.x,
            0));

      if (left) {

        position -= STEP * lateral * delta;

      } else if (right) {

        position += STEP * lateral * delta;

      }
    }
  }
}

void app::scene::FPSCamera::use() {
  glm::vec3 target(
      sin(rho) * cos(theta) + position.x,
      cos(rho) * cos(theta) + position.y,
      sin(theta) + position.z);

  shaders.getDiffuseShader().bindViewMatrix(
      glm::lookAt(
        position,
        target,
        glm::vec3(0.0, 0.0, 1.0)));
}
