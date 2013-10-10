#ifndef __APP_SCENE_CAMERA_H_INCLUDED__
#define __APP_SCENE_CAMERA_H_INCLUDED__

#include "sys/events.h"
#include "sys/window.h"
#include "sys/input.h"
#include "app/shaders/register.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class Camera :
      public sys::MouseMotionListener,
      public sys::KeyUpListener,
      public sys::KeyDownListener {

      public:
        Camera(sys::Window &window, sys::Input &input, const app::shaders::Register &shaders);

        virtual void onMouseMotion(const sys::MouseMotionEvent &event);
        virtual void onKeyUp(const sys::KeyUpEvent &event);
        virtual void onKeyDown(const sys::KeyDownEvent &event);
        virtual glm::mat4 use();

        virtual void doMouseMove(int deltaX, int deltaY) = 0;
        virtual void doKeyUp(unsigned char key) = 0;
        virtual void doKeyDown(unsigned char key) = 0;
        virtual void tick(float delta) = 0;
        virtual glm::mat4 getViewMatrix() = 0;

        virtual ~Camera() {};
      protected:
        sys::Window &window;
        const app::shaders::Register &shaders;
    };
  };
};

#endif
