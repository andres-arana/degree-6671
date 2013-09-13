#ifndef __SYS_APPLICATION_H_INCLUDED__
#define __SYS_APPLICATION_H_INCLUDED__

namespace sys {
  class Renderer {
    public:
      virtual void render() = 0;

      virtual ~Renderer() {};
  };

  class Dispatcher {
    public:
      virtual ~Dispatcher() {};

      virtual void onClose() {};

      virtual void onReshape(int width, int height) {};

      virtual void onMouse(int button, int updown, int x, int y) {};

      virtual void onMouseWheel(int whellNumber, int direction, int x, int y) {};

      virtual void onMouseMotion(int x, int y) {};

      virtual void onSpecialKeyUp(int key, int x, int y) {};

      virtual void onKeyUp(unsigned char key, int x, int y) {};

      virtual void onSpecialKeyDown(int key, int x, int y) {};

      virtual void onKeyDown(unsigned char key, int x, int y) {};

      virtual void onIdle() {};
  };

  class Application {
    public:
      virtual unsigned int getWidth() = 0;

      virtual unsigned int getHeight() = 0;

      virtual unsigned int getPositionX() = 0;

      virtual unsigned int getPositionY() = 0;

      virtual const char* getTitle() = 0;

      virtual Renderer &getRenderer() = 0;

      virtual Dispatcher &getDispatcher() = 0;

      virtual ~Application() {};

  };

};

#endif
