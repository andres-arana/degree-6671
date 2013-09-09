#include <cstdlib>
#include "application.h"
#include "fwk/system.h"
#include "fwk/window.h"

int main(int argc, char** argv) {
  Application application = Application();

  fwk::System system = fwk::System(argc, argv);
  fwk::Window &window = system.createWindow(application, "66.71 - Sistemas Graficos - UBA 2013", 640, 480);

  system.runEventLoop();

  return EXIT_SUCCESS;
}
