#include "app/scene/camera.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

using namespace app;
using namespace app::scene;
using namespace sys;

Camera::Camera(Window &window, Input &input, const shaders::Register &shaders) :
  window(window),
  shaders(shaders) {
    input.addMouseMotionListener(*this);
    input.addKeyUpListener(*this);
    input.addKeyDownListener(*this);
  }

void Camera::onMouseMotion(const MouseMotionEvent &event) {
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

void Camera::onKeyUp(const KeyUpEvent &event) {
  doKeyUp(event.key);
}

void Camera::onKeyDown(const KeyDownEvent &event) {
  doKeyDown(event.key);
}

glm::mat4 Camera::use() {
  auto viewMatrix = getViewMatrix();
  shaders.getDiffuseShader().bindViewMatrix(viewMatrix);
  shaders.getDiffuseShader().bindProjectionMatrix(glm::infinitePerspective(
        52.0f, window.getAspectRatio(), 0.1f));

  return viewMatrix;
}
