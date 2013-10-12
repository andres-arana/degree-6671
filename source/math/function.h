#ifndef __MATH_FUNCTION_H_INCLUDED__
#define __MATH_FUNCTION_H_INCLUDED__

#include <glm/glm.hpp>

namespace math {
  class function {
    public:
      virtual glm::vec3 apply(float x) const = 0;
      virtual glm::vec3 apply_derivate(float x) const = 0;

      virtual ~function() {};
  };
};

#endif
