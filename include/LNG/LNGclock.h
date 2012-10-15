/*
  LNGclock.h
*/

#ifndef __LNGclock_H__
#define __LNGclock_H__

#include <LNG/LNGut.h>

class LNGclock {
public:
  LNGcoord3f fps_pos;
  LNGcolor4f fps_col;
  static LNGcoord3f const default_pos;
  static LNGcolor4f const default_col;
protected:
  GLuint const fps_desired;
  bool fps_visible;
  GLuint fps, fps_clk, fps_pclk, fps_nclk, frames;
public:
  LNGclock(GLuint a_fps_desired);
  virtual ~LNGclock();
  GLuint FPSdesired(void) {return fps_desired;}
  virtual bool FPSvisible(void) {return fps_visible;}
  virtual bool FPSvisible(bool visible) {return fps_visible = visible;}
  virtual void FPS(void);
  virtual void FPSdisplay(void);
};

#endif
