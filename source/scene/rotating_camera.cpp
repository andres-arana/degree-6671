#include "scene/rotating_camera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>
#include <glm/gtx/constants.hpp> 
#include <cmath>

#define STEP 10.0f

using namespace scene;

rotating_camera::rotating_camera(
    sys::window &window,
    sys::input &input,
    const glm::vec3 &center,
    float distance,
    const shaders::cache &shaders) :
  camera(window, input, shaders),
  center(center),
  distance(distance),
  rho(glm::half_pi<float>()),
  forwards(false),
  backwards(false) {

  }

void rotating_camera::do_mouse_move(int delta_x, int delta_y) {
  if (delta_x == 0 && delta_y == 0) {
    return;
  }

  if (delta_x) {
    rho += delta_x * 0.005f;
    if (rho > 2 * glm::pi<float>()) {
      rho -= 2 * glm::pi<float>();
    } else if (rho < 0) {
      rho += 2 * glm::pi<float>();
    }
  }

  if (delta_y) {
    theta += delta_y * 0.005f;
    if (theta >= glm::half_pi<float>()) {
      theta = glm::half_pi<float>();
    } else if (theta <= -glm::half_pi<float>()) {
      theta = -glm::half_pi<float>();
    }
  }
}


void rotating_camera::do_key_up(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = false;
  }

  if(key == 's' || key == 'S') {
    backwards = false;
  }
}

void rotating_camera::do_key_down(unsigned char key) {
  if (key == 'w' || key == 'W') {
    forwards = true;
  }

  if(key == 's' || key == 'S') {
    backwards = true;
  }

}

void rotating_camera::tick(float delta) {
  if (forwards) {
    distance -= STEP * delta;
  }

  if (backwards) {
    distance += STEP * delta;
  }
}

glm::mat4 rotating_camera::get_view_matrix() {
  glm::vec3 position(
      distance * sin(rho) * cos(theta) + center.x,
      distance * cos(rho) * cos(theta) + center.y,
      distance * sin(theta) + center.z);

  return glm::lookAt(
        position,
        center,
        glm::vec3(0.0, 0.0, 1.0));
}
