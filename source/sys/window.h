#ifndef __SYS_WINDOW_H_INCLUDED__
#define __SYS_WINDOW_H_INCLUDED__

#include "sys/params.h"
#include "sys/init/glut.h"

namespace sys {
  class window {
    public:
      window(const init::glut &glut, const params &params);

      window(const window &other) = delete;
      window &operator=(const window &other) = delete;

      void toggle_full_screen();

      void hide_cursor();

      void show_cursor();

      void swap_buffers();

      float get_aspect_ratio() const;

      int get_width() const;

      int get_height() const;

      void set_cursor_position(int x, int y);
    private:

      unsigned int id;
  };
};

#endif
