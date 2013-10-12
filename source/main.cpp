#include <cstdlib>
#include "application.h"
#include "sys/system.h"
#include "sys/params.h"

int main(int argc, char** argv) {
  sys::Params params;
  params.argc = &argc;
  params.argv = argv;
  params.width = 800;
  params.height = 600;
  params.title = "66.71 - Sistemas Graficos - FIUBA";

  sys::System<Application> system(params);

  system.runEventLoop();

  return EXIT_SUCCESS;
}
