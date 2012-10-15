/*
  rcube.h
*/

#ifndef __RCUBE_H__
#define __RCUBE_H__

#include <LNG/LNG3Dframe.h>

class RCube : public LNG3Dframe {
protected:
  GLfloat distance;
  GLuint angle;
public:
  RCube();
  virtual ~RCube();
  virtual void Finalize(void);
  virtual void LoadTextures(void);
  virtual void InitGL(void);
  virtual void Update(void);
  virtual void ChangeAngle(void);
  virtual void DisplayDraw(void);
};

#endif
