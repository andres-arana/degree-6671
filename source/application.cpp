#include "application.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

Application::Application() {

}

void Application::onInit() {
  glClearColor(0.1f, 0.1f, 0.2f, 0.0f);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
}

void Application::onDisplay() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glutSwapBuffers();
}

void Application::onKeyUp(unsigned char key, int x, int y) {
  if (key == 'f') {
    glutFullScreenToggle();
  } else if (key == 0x1b) {
    glutLeaveMainLoop();
  }
}

Application::~Application() {

}
