#ifndef __APP_SCENE_CAMERA_H_INCLUDED__
#define __APP_SCENE_CAMERA_H_INCLUDED__

namespace app {
  namespace scene {
    class Camera {
      public:
        virtual void onMouseMove(int deltaX, int deltaY) = 0;

        virtual void onKeyUp(unsigned char key) = 0;

        virtual void onKeyDown(unsigned char key) = 0;

        virtual void tick(float delta) = 0;

        virtual void use() = 0;

        virtual ~Camera() {};
    };
  };
};

#endif
