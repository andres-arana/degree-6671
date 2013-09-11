#ifndef __FWK__DISPATCHER_H_INCLUDED__
#define __FWK__DISPATCHER_H_INCLUDED__

namespace fwk {

  class Dispatcher {
    public:

      virtual void onInit();

      virtual void onDisplay();

      virtual void onClose();

      virtual void onReshape(int width, int height);

      virtual void onMouse(int button, int updown, int x, int y);

      virtual void onMouseWheel(int whellNumber, int direction, int x, int y);

      virtual void onMouseMotion(int x, int y);

      virtual void onSpecialKeyUp(int key, int x, int y);

      virtual void onKeyUp(unsigned char key, int x, int y);

      virtual void onSpecialKeyDown(int key, int x, int y);

      virtual void onKeyDown(unsigned char key, int x, int y);

      virtual void onIdle();

      virtual ~Dispatcher() {};
  };

};

#endif
