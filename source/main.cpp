#include <cstdlib>
#include "app/application.h"
#include "sys/system.h"

int main(int argc, char** argv) {
  app::Application  application();
  sys::System       system(argc, argv);

  system
    .createContext(application)
    .runEventLoop();

  fwk::Window &window = system.createWindow(application, "66.71 - Sistemas Graficos - UBA 2013", 640, 480);

  return EXIT_SUCCESS;
}
