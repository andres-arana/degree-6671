#include "app/application.h"

app::Application::Application() :
  renderer(0),
  dispatcher(0) {

}

unsigned int app::Application::getWidth(){
  return 800;
}

unsigned int app::Application::getHeight(){
  return 600;
}

unsigned int app::Application::getPositionX(){
  return 0;
}

unsigned int app::Application::getPositionY(){
  return 0;
}

const char* app::Application::getTitle(){
  return "66.71 - Sistemas Graficos - FIUBA";
}

sys::Renderer &app::Application::getRenderer(){
  if (!renderer) {
    renderer = new app::Renderer();
  }
  return *renderer;
}

sys::input::Dispatcher &app::Application::getDispatcher(){
  if (!dispatcher) {
    dispatcher = new app::Dispatcher();
  }
  return *dispatcher;
}

app::Application::~Application() {
  if (dispatcher) {
    delete dispatcher;
  }

  if (renderer) {
    delete renderer;
  }
}
