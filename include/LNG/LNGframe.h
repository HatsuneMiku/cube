/*
  LNGframe.h
*/

#ifndef __LNGframe_H__
#define __LNGframe_H__

#include <LNG/LNGut.h>
#include <LNG/LNGclock.h>
#include <LNG/LNGpng.h>
#include <LNG/LNGtexture.h>
#include <LNG/LNGcameleon_texture.h>
#include <LNG/LNGchar_texture.h>

class LNGframe;
class LNGdispatcher;

class LNGframe {
public:
  static GLuint const default_fps;
  static LNGsize const default_size;
  static LNGpoint const default_pos;
protected:
  bool done;
  LNGdispatcher *dispatcher;
  LNGclock *clk;
  LNGloader *loader;
public:
  LNGframe(GLuint fps_desired=default_fps);
  virtual ~LNGframe();
  virtual void Finalize(void);
  virtual void InitFrame(int *ac, char **av, std::string &title,
    LNGsize size=default_size, LNGpoint pos=default_pos,
    GLuint mode=GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  virtual void MainLoop(void);
  virtual void Quit(int n);
  virtual void LoadTextures(void) {}
  virtual void InitGL(void);
  virtual void Timer(int dt);
  virtual void Idle(void);
  virtual void Update(void);
  virtual void ChangeAngle(void) {}
  virtual void ChangeView(void);
  virtual void DisplayBefore(void);
  virtual void DisplayDraw(void);
  virtual void DisplayAfter(void);
  virtual void Display(void);
  virtual void Ortho(
    float x0, float x1, float y0, float y1, float z0, float z1) {}
  virtual void Perspective(int w, int h) {}
  virtual void Reshape(int w, int h);
  virtual void KeyPress(unsigned char key, int x, int y);
  virtual void SpecialKeyPress(int key, int x, int y);
  virtual void LeftDown(int button, int state, int x, int y) {}
  virtual void LeftUp(int button, int state, int x, int y) {}
  virtual void MiddleDown(int button, int state, int x, int y) {}
  virtual void MiddleUp(int button, int state, int x, int y) {}
  virtual void RightDown(int button, int state, int x, int y) {}
  virtual void RightUp(int button, int state, int x, int y) {}
  virtual void MouseAction(int button, int state, int x, int y);
  virtual void Motion(int x, int y);
  virtual void PassiveMotion(int x, int y);
};

class LNGdispatcher {
protected:
  static LNGframe *frame;
public:
  LNGdispatcher(LNGframe *aframe) {frame = aframe;}
  virtual ~LNGdispatcher() {frame = 0;}
  static void Finalize(void) {if(frame) frame->Finalize();}
  static void Quit(int n) {if(frame) frame->Quit(n);}
  static void Timer(int dt) {frame->Timer(dt);}
  static void Idle(void) {frame->Idle();}
  static void Display(void) {frame->Display();}
  static void Reshape(int w, int h) {frame->Reshape(w, h);}
  static void KeyPress(unsigned char key, int x, int y)
    {frame->KeyPress(key, x, y);}
  static void SpecialKeyPress(int key, int x, int y)
    {frame->SpecialKeyPress(key, x, y);}
  static void MouseAction(int button, int state, int x, int y)
    {frame->MouseAction(button, state, x, y);}
  static void Motion(int x, int y) {frame->Motion(x, y);}
  static void PassiveMotion(int x, int y) {frame->PassiveMotion(x, y);}
};

#endif
