#include "app/scene/options.h"
#include <GL/glew.h>

using namespace app::scene;

Options::Options(float red, float green, float blue) {
  glClearColor(red, green, blue, 0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
}
