/*
  LNGchar_texture.h
*/

#ifndef __LNGchar_texture_H__
#define __LNGchar_texture_H__

#include <LNG/LNGtexture.h>

class LNGchar_texture : public LNGtexture {
protected:
public:
  LNGchar_texture(std::string &afilename,
    bool kb=false, bool ac=false, bool cp=false, bool cd=false,
    GLuint abpp=LNGtexture::default_bytes_par_pixel,
    LNGsize asize=LNGtexture::default_size,
    std::string const &aresource_dir=LNGtexture::default_resource_dir);
  virtual ~LNGchar_texture();
  virtual GLubyte AlphaCallback(GLubyte r, GLubyte g, GLubyte b)
    {return (255 - (r + g + b) / 3) & 0x00FF;}
};

#endif
