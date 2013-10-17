#include "math/cyclic_interval.h"

float normalize(float value, float min, float max) {
  if (value >= max) {
    return value - max + min;
  } else if (value <= min) {
    return value - min + max;
  } else {
    return value;
  }
}

using namespace math;

cyclic_interval::cyclic_interval(float min, float max) :
  min(min),
  max(max),
  current(min) {

  }

void cyclic_interval::advance(float t) {
  current = normalize(current + t, min, max);

}

float cyclic_interval::get() const {
  return current;
}

float cyclic_interval::displaced_get(float delta) const {
  return normalize(current + delta, min, max);
}

