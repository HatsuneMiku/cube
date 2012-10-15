/*
  LNGpng.h
*/

#ifndef __LNGpng_H__
#define __LNGpng_H__

#include <LNG/LNGut.h>

class LNGpng {
public:
  LNGsize size;
  GLuint depth, col_type, interlace_type, compress_type, filter_type;
  GLuint png_depth, p_depth, b_depth, pals, num_pals, alpha, row_bytes;
  GLubyte *image;
  png_color *palette; // sizeof(png_color) (== 3 bytes) * pals (>= num_pals)
public:
  LNGpng();
  virtual ~LNGpng();
  virtual void Finalize(void);
  static void C4hFunc(png_structp png_ptr, png_row_infop ri, png_bytep data);
  static void ReadFunc(png_structp png_ptr, png_bytep data, png_size_t length);
  virtual bool LoadRaw(std::string &filepath);
};

#endif
