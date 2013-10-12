#include "scene/world.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/constants.hpp> 

using namespace scene;
using namespace sys;

world::world(
    window &window,
    input &input) :
  fps_camera(window, input, glm::vec3(12.0f, 0, 1.0f), shaders),
  rotating_camera(window, input, glm::vec3(0, 0, 1.0f), 12.0f, shaders),
  floor(geometries, shaders),
  light(shaders),
  crab(geometries, shaders),
  current_camera(&rotating_camera),
  rotation(0) {

    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

  }

void world::render() {
  auto model_matrix = glm::mat4(1.0f);
  auto view_matrix = current_camera->use();

  auto light_matrix = glm::translate(model_matrix, glm::vec3(0, 0, 5));
  light_matrix = glm::rotate(light_matrix, rotation, glm::vec3(0, 0, 1));
  light_matrix = glm::translate(light_matrix, glm::vec3(4.0f, 0, 0));
  light.use(view_matrix, light_matrix);

  floor.render(model_matrix);

  auto crab_matrix = glm::translate(model_matrix, glm::vec3(0, 0, 1.75f));
  crab.render(crab_matrix);
}

void world::tick(float delta) {
  current_camera->tick(delta);
  rotation += (60 * delta);
  if (rotation > 360) {
    rotation -= 360;
  }
}

void world::toggle_camera() {
  if (current_camera == &rotating_camera) {
    current_camera = &fps_camera;
  } else {
    current_camera = &rotating_camera;
  }
}
