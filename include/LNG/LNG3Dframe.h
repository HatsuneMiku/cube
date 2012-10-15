/*
  LNG3Dframe.h
*/

#ifndef __LNG3Dframe_H__
#define __LNG3Dframe_H__

#include <LNG/LNGframe.h>

class LNG3Dframe : public LNGframe {
public:
  LNG3Dframe(GLuint fps_desired=LNGframe::default_fps) :
    LNGframe(fps_desired) {}
  virtual ~LNG3Dframe() {}
  virtual void ChangeAngle(void);
  virtual void Perspective(int w, int h);
};

#endif
