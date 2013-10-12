#ifndef __MATH_FUNCTION_H_INCLUDED__
#define __MATH_FUNCTION_H_INCLUDED__

#include <glm/glm.hpp>

namespace math {
  class Function {
    public:
      virtual glm::vec3 apply(float x) const = 0;
      virtual glm::vec3 applyDerivate(float x) const = 0;

      virtual ~Function() {};
  };
};

#endif
