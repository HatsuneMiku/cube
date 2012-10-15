/*
  rcube.cpp
*/

#include "rcube.h"

using namespace std;

RCube::RCube() : distance(5.0), angle(0)
{
  // clk->FPSvisible(false);
  clk->fps_pos = LNGcoord3f(-0.5, 0.8, -0.8);
  clk->fps_col = LNGcolor4f(0.2, 0.8, 0.4, 0.9);
}

RCube::~RCube()
{
}

void RCube::Finalize(void)
{
  LNG3Dframe::Finalize();
}

void RCube::LoadTextures(void)
{
  for(int i = 0; i < 6; i++){
    ostringstream oss;
    oss << "f" << i << ".png";
    loader->Append(new LNGtexture(oss.str(), !i));
  }
  for(int i = 0; i < 6; i++)
    loader->Append(
      new LNGcameleon_texture(i, string("72dpi.png"), false, false, true));
  char *fn[] = {"72dpi_ascii_reigasou_16x16.png"};
  for(int i = 0; i < sizeof(fn) / sizeof(fn[0]); i++)
    loader->Append(new LNGchar_texture(string(fn[i])));
}

void RCube::InitGL(void)
{
  LNG3Dframe::InitGL();
}

void RCube::Update(void)
{
  angle = (angle + 1) % 360;
  LNG3Dframe::Update();
}

void RCube::ChangeAngle(void)
{
  glTranslatef(0.0, 0.0, -distance);
  glRotatef(angle, 0, 1, 0);
}

void RCube::DisplayDraw(void)
{
  LNG3Dframe::DisplayDraw();

  glColor4f(1.0, 1.0, 1.0, 1.0);
  glEnable(GL_TEXTURE_2D);
//  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//  glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
//  glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
  glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
  glEnable(GL_BLEND);
  LNGtexture *h = loader->At(6);
  if(h && !h->loading){
    glBindTexture(GL_TEXTURE_2D, h->id);
    glBegin(GL_QUADS);
      // reverse top / bottom
      glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.5, -0.5, -1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f( 0.5,  0.5, -1.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-0.5,  0.5, -1.0);
    glEnd();
  }
  LNGtexture *c = loader->Back();
  if(c && !c->loading){
    glBindTexture(GL_TEXTURE_2D, c->id);
    glBegin(GL_QUADS);
      // reverse top / bottom
      glTexCoord2f(0.0, 0.0); glVertex3f( 0.0, -0.4,  1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.8, -0.4,  1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f( 0.8,  0.4,  1.0);
      glTexCoord2f(0.0, 1.0); glVertex3f( 0.0,  0.4,  1.0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, c->id);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0625, 0.6875); glVertex3f(-0.1, -0.1, 1.1);
      glTexCoord2f(0.1250, 0.6875); glVertex3f( 0.1, -0.1, 1.1);
      glTexCoord2f(0.1250, 0.7500); glVertex3f( 0.1,  0.1, 1.1);
      glTexCoord2f(0.0625, 0.7500); glVertex3f(-0.1,  0.1, 1.1);
    glEnd();
  }
  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
}

int main(int ac, char **av)
{
  try{
    RCube frm;
    string title = "rcube";
#ifdef _DEBUG
    frm.InitFrame(&ac, av, title, LNGsize(240, 320), LNGpoint(40, 40));
#endif
    frm.InitFrame(&ac, av, title);
    frm.MainLoop();
  }catch(LNGexception &e){
    cout << e.getstr() << endl;
#if defined( __TRACE_DESTRUCTION__ ) || defined( _DEBUG )
    cout << "after LNGexception in main" << endl;
#endif
  }
#if defined( __TRACE_DESTRUCTION__ ) || defined( _DEBUG )
  cout << "now return from main" << endl;
#endif
  return 0;
}
