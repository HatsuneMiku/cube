/*
  LNGtypes.h
*/

#ifndef __LNGtypes_H__
#define __LNGtypes_H__

#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>

#include <zlib.h>
#include <png.h>
#include <GL/glut.h>

#define default_LNGexception_str "default LNGexception"

class LNGexception {
protected:
  std::string str;
public:
  LNGexception(char *astr=default_LNGexception_str) : str(astr) {}
  LNGexception(std::string &astr) : str(astr) {}
  virtual ~LNGexception() {}
  virtual std::string &getstr(void) {return str;}
};

typedef struct LNGsize {
  GLuint w, h;
public:
  LNGsize(GLuint aw, GLuint ah) : w(aw), h(ah) {}
} LNGsize;

typedef struct LNGpoint {
  GLuint x, y;
public:
  LNGpoint(GLuint ax, GLuint ay) : x(ax), y(ay) {}
} LNGpoint;

typedef struct LNGcoord2f {
  GLfloat x, y;
public:
  LNGcoord2f(GLfloat ax, GLfloat ay) : x(ax), y(ay) {}
} LNGcoord2f;

typedef struct LNGcoord3f {
  GLfloat x, y, z;
public:
  LNGcoord3f(GLfloat ax, GLfloat ay, GLfloat az) : x(ax), y(ay), z(az) {}
} LNGcoord3f;

typedef struct LNGcolor4f {
  GLfloat r, g, b, a;
public:
  LNGcolor4f(GLfloat ar, GLfloat ag, GLfloat ab, GLfloat aa) :
    r(ar), g(ag), b(ab), a(aa) {}
} LNGcolor4f;

#endif
