#include "application.h"

application::application(sys::system<application> &system, sys::window &window, sys::input &input) :
  system(system),
  window(window),
  input(input),
  world(window, input),
  previous_time(0) {
    window.hide_cursor();
    input.disable_key_repeat_events();

    input.set_render_listener(*this);
    input.add_reshape_listener(*this);
    input.add_key_up_listener(*this);
    input.add_idle_listener(*this);
  }

void application::on_render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  world.render();

  window.swap_buffers();
}

void application::on_reshape(const sys::reshape_event &event) {
  glViewport(0, 0, (GLsizei) event.width, (GLsizei) event.height);
}

void application::on_key_up(const sys::key_up_event &event) {
  if (event.key == 'f') {
    window.toggle_full_screen();
  } else if (event.key == 'c') {
    world.toggle_camera();
  } else if (event.key == 0x1b) {
    system.exit_event_loop();
  }
}

void application::on_idle(const sys::idle_event &event) {
  (void)event;

  if (!previous_time) {
    previous_time = system.get_time();
    return;
  }

  auto current_time = system.get_time();
  auto delta = (current_time - previous_time) / 1000.0f;

  world.tick(delta);

  previous_time = current_time;
}

