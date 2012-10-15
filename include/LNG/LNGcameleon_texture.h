/*
  LNGcameleon_texture.h
*/

#ifndef __LNGcameleon_texture_H__
#define __LNGcameleon_texture_H__

#include <LNG/LNGtexture.h>

class LNGcameleon_texture : public LNGtexture {
protected:
  GLuint norm;
public:
  LNGcameleon_texture(GLuint n, std::string &afilename,
    bool kb=false, bool ac=false, bool cp=false, bool cd=false,
    GLuint abpp=LNGtexture::default_bytes_par_pixel,
    LNGsize asize=LNGtexture::default_size,
    std::string const &aresource_dir=LNGtexture::default_resource_dir);
  virtual ~LNGcameleon_texture();
  virtual GLubyte *CustomPixel(GLubyte *buf);
};

#endif
