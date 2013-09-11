#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

#include "fwk/dispatcher.h"

class Application : public fwk::Dispatcher {
  public:
    Application();

    virtual void onInit();

    virtual void onDisplay();

    virtual void onKeyUp(unsigned char key, int x, int y);

    virtual ~Application();
};

#endif
