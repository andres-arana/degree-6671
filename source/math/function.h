#ifndef __MATH_FUNCTION_H_INCLUDED__
#define __MATH_FUNCTION_H_INCLUDED__

namespace math {
  template<typename I, typename O> class function {
    public:
      virtual O operator()(const I &x) const = 0;

      virtual ~function() {};
  };
};

#endif
