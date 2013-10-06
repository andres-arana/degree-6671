#include "app/scene/FPSCamera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <cmath>

#define PI 3.1415f
#define STEP 0.2f

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
  if (key == 'w' || key == 'W' ||
      key == 's' || key == 'S' ||
      key == 'a' || key == 'A' ||
      key == 'd' || key == 'D') {

    glm::vec3 displacement(
        sin(rho) * cos(theta),
        cos(rho) * cos(theta),
        sin(theta));

    if (key == 'w' || key == 'W') {

      position += STEP * displacement;

    } else if (key == 's' || key == 'S') {

      position -= STEP * displacement;

    } else if (key == 'a' || key == 'A' ||
               key == 'd' || key == 'D') {

      // The cross product between the displacement vector (forward facing) and
      // the up vector is the lateral stepping vector, which should be
      // normalized to ensure proper scaling later
      glm::vec3 lateral = glm::normalize(glm::vec3(
            displacement.y,
            -displacement.x,
            0));

      if (key == 'a' || key == 'A') {
        position -= STEP * lateral;
      } else if (key == 'd' || key == 'D') {
        position += STEP * lateral;
      }


    }

    if (key == 'd' || key == 'D') {

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
