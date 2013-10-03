#ifndef __APP_SHADERS_REGISTER_H_INCLUDED__
#define __APP_SHADERS_REGISTER_H_INCLUDED__

#include "app/shaders/diffuseShader.h"

namespace app {
  namespace shaders {
    class Register {
      public:
        Register();

        const DiffuseShader &getDiffuseShader() const;

      private:
        DiffuseShader diffuseShader;
    };
  };
};

#endif
