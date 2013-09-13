#ifndef __APP_RENDERER_H_INCLUDED__
#define __APP_RENDERER_H_INCLUDED__

#include "sys/application.h"

namespace app {

  class Renderer : public sys::Renderer {
    public:
      Renderer();

      virtual void render();
  };

};

#endif
