#include "app/application.h"
#include "sys/window.h"

app::Application::Application() {

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

void app::Application::configureWindow(sys::Window &window) {
  window.hideCursor();
}

sys::Renderer &app::Application::getRenderer(){
  if (!renderer.get()) {
    std::auto_ptr<app::Renderer> newRenderer(new app::Renderer());
    renderer = newRenderer;
  }
  return *renderer;
}

sys::input::Dispatcher &app::Application::getDispatcher(){
  if (!dispatcher.get()) {
    std::auto_ptr<app::Dispatcher> newDispatcher(new app::Dispatcher(*this));
    dispatcher = newDispatcher;
  }
  return *dispatcher;
}

app::scene::Camera &app::Application::getCamera() {
  return renderer->getCamera();
}

void app::Application::toggleCamera() {
  renderer->toggleCamera();
}
