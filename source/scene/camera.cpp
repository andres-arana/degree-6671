#include "scene/camera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

using namespace scene;

Camera::Camera(
    sys::Window &window,
    sys::Input &input,
    const shaders::Cache &shaders) :
  window(window),
  shaders(shaders) {
    input.addMouseMotionListener(*this);
    input.addKeyUpListener(*this);
    input.addKeyDownListener(*this);
  }

void Camera::onMouseMotion(const sys::MouseMotionEvent &event) {
  int middleX = window.getWidth() / 2;
  int middleY = window.getHeight() / 2;

  int deltaX = event.x - middleX;
  int deltaY = event.y - middleY;

  if (deltaX < 3 && deltaX > -3) {
    deltaX = 0;
  }

  if (deltaY < 3 && deltaY > -3) {
    deltaY = 0;
  }

  if (deltaX || deltaY) {
    doMouseMove(deltaX, deltaY);
    window.setCursorPosition(middleX, middleY);
  }
}

void Camera::onKeyUp(const sys::KeyUpEvent &event) {
  doKeyUp(event.key);
} 
void Camera::onKeyDown(const sys::KeyDownEvent &event) {
  doKeyDown(event.key);
}

glm::mat4 Camera::use() {
  auto viewMatrix = getViewMatrix();
  shaders.basic.bindViewMatrix(viewMatrix);
  shaders.basic.bindProjectionMatrix(glm::infinitePerspective(
        52.0f, window.getAspectRatio(), 0.1f));

  return viewMatrix;
}
