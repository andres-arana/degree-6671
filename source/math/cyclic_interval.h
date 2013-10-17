#ifndef __MATH_CYCLIC_INTERVAL_H_INCLUDED__
#define __MATH_CYCLIC_INTERVAL_H_INCLUDED__

namespace math {
  class cyclic_interval {
    public:
      cyclic_interval(float min, float max);

      void advance(float t);

      float get() const;

      float displaced_get(float delta) const;

    private:
      float min;
      float max;
      float current;
  };
};

#endif
