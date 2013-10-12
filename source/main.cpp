#include <cstdlib>
#include "application.h"
#include "sys/system.h"
#include "sys/params.h"

int main(int argc, char** argv) {
  sys::params params;
  params.argc = &argc;
  params.argv = argv;
  params.width = 800;
  params.height = 600;
  params.title = "66.71 - Sistemas Graficos - FIUBA";

  sys::system<application> system(params);

  system.run_event_loop();

  return EXIT_SUCCESS;
}
