#ifndef __MATH_LINEAR_INTERPOLATION_H_INCLUDED__
#define __MATH_LINEAR_INTERPOLATION_H_INCLUDED__

#include <vector>
#include <utility>
#include <algorithm>

namespace math {
  template<typename T> class linear_interpolation {
    public:
      linear_interpolation(std::initializer_list<std::pair<float, T>> points);

      T operator()(float t) const;
    private:
      std::vector<std::pair<float, T>> points;
  };

  template<typename T>
    linear_interpolation<T>::linear_interpolation(std::initializer_list<std::pair<float, T>> points) :
      points(points) {

      }

  template<typename T>
    T linear_interpolation<T>::operator()(float t) const {
      for (auto pi = points.begin(); pi != points.end(); pi++) {
        if (t >= pi->first) {
          auto pf = (pi == points.begin() ?  points.end() - 1 : pi - 1);

          return pi->second + ((pf->second - pi->second) / (pf->first - pi->first)) * (t - pi->first);
        }
      }

      return T();
    }
};


#endif
