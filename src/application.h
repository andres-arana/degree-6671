#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

#include "fwk/dispatcher.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

class Application : public fwk::Dispatcher {
  public:
    virtual void onDisplay() {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glutSwapBuffers();
    }

    virtual ~Application() {

    }

  private:
};

#endif
