#include "scene/camera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

using namespace scene;

camera::camera(
    sys::window &window,
    sys::input &input,
    const shaders::cache &shaders) :
  window(window),
  shaders(shaders) {
    input.add_mouse_motion_listener(*this);
    input.add_key_up_listener(*this);
    input.add_key_down_listener(*this);
  }

void camera::on_mouse_motion(const sys::mouse_motion_event &event) {
  int middle_x = window.get_width() / 2;
  int middle_y = window.get_height() / 2;

  int delta_x = event.x - middle_x;
  int delta_y = event.y - middle_y;

  if (delta_x < 3 && delta_x > -3) {
    delta_x = 0;
  }

  if (delta_y < 3 && delta_y > -3) {
    delta_y = 0;
  }

  if (delta_x || delta_y) {
    do_mouse_move(delta_x, delta_y);
    window.set_cursor_position(middle_x, middle_y);
  }
}

void camera::on_key_up(const sys::key_up_event &event) {
  do_key_up(event.key);
} 
void camera::on_key_down(const sys::key_down_event &event) {
  do_key_down(event.key);
}

glm::mat4 camera::use() {
  auto view_matrix = get_view_matrix();
  shaders.basic.bind_view_matrix(view_matrix);
  shaders.basic.bind_projection_matrix(glm::infinitePerspective(
        52.0f, window.get_aspect_ratio(), 0.1f));

  return view_matrix;
}
