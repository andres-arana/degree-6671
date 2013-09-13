#ifndef __SYS_GLEW_H_INCLUDED__
#define __SYS_GLEW_H_INCLUDED__

namespace sys {

  class Context;

  class Glew {
    private:
      friend class Context;

      Glew();
      Glew(const Glew & other);
      Glew &operator=(const Glew &other);
  };

};

#endif
