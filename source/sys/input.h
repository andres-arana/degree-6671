#ifndef __SYS_INPUT_H_INCLUDED__
#define __SYS_INPUT_H_INCLUDED__

#include "sys/events.h"
#include "sys/init/glut.h"
#include <vector>


namespace sys {
  class Input {
    public:
      Input(const sys::init::Glut &glut);

      Input(const Input &other) = delete;
      Input &operator=(const Input &other) = delete;

      void disableKeyRepeatEvents();

      void addCloseListener(CloseListener &listener);
      void addReshapeListener(ReshapeListener &listener);
      void addMouseListener(MouseListener &listener);
      void addMouseMotionListener(MouseMotionListener &listener);
      void addKeyUpListener(KeyUpListener &listener);
      void addKeyDownListener(KeyDownListener &listener);
      void addIdleListener(IdleListener &listener);
      void setRenderListener(RenderListener &listener);

    private:

      RenderListener *renderListener;
      std::vector<CloseListener *> closeListeners;
      std::vector<ReshapeListener *> reshapeListeners;
      std::vector<MouseListener *> mouseListeners;
      std::vector<MouseMotionListener *> mouseMotionListeners;
      std::vector<KeyUpListener *> keyUpListeners;
      std::vector<KeyDownListener *> keyDownListeners;
      std::vector<IdleListener *> idleListeners;

      static Input *instance;

      static void onDisplay();
      static void onClose();
      static void onReshape(int width, int height);
      static void onMouse(int button, int updown, int x, int y);
      static void onMouseMotion(int x, int y);
      static void onKeyUp(unsigned char key, int x, int y);
      static void onKeyDown(unsigned char key, int x, int y);
      static void onIdle();
  };
};

#endif
