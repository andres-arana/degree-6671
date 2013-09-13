#include <cstdlib>
#include "app/application.h"
#include "sys/system.h"

int main(int argc, char** argv) {
  app::Application  application;
  sys::System       system(argc, argv);

  system
    .createContext(application)
    .runEventLoop();

  return EXIT_SUCCESS;
}
