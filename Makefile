OUTPUT = rcube.exe
LDIR   = lib/
HDIR   = include/LNG/
HEADS0 = $(HDIR)LNGclock.h $(HDIR)LNGut.h $(HDIR)LNGtypes.h
HEADS1 = $(HDIR)LNGtexture.h $(HDIR)LNGpng.h
HEADS2 = $(HDIR)LNGchar_texture.h $(HDIR)LNGcameleon_texture.h
HEADS3 = $(HDIR)LNG3Dframe.h $(HDIR)LNG2Dframe.h $(HDIR)LNGframe.h
HEADS  = $(HEADS3) $(HEADS2) $(HEADS1) $(HEADS0)
TDIR   = src/
ODIR   = obj/
LIBS   = liblng.lib zlib1.lib libpng15.lib glui32dll.lib glut32.lib
CC     = cl
CPPTR0 = $(TRACE_CONSTRUCTION) $(TRACE_DESTRUCTION)
CPPTR1 = $(TRACE_CREATION) $(TRACE_FINALIZATION)
CPPDEF = $(TEST_GLUI)
CFLAGS = $(CPPDEF) $(CPPTR1) $(CPPTR0) -nologo -EHsc -Iinclude
SUBSYS = -SUBSYSTEM:console
NOLIB  = -NODEFAULTLIB:libc
LOPT   = -nologo -link
LINK   = cl
#LINK   = link
LPATH0 = -LIBPATH:$(LDIR)
#LPATH1 = -LIBPATH:"C:\Program Files\Microsoft SDKs\Windows\v6.0A\lib"
#LPATH2 = -LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\lib"
LPALL  = $(LPATH2) $(LPATH1) $(LPATH0)
LFLAGS = -NOLOGO $(LPALL) $(SUBSYS) $(NOLIB)
LIBEXE = lib

$(OUTPUT) : $(ODIR)$(*B).obj $(LDIR)liblng.lib
	$(LINK) $(ODIR)$(*B).obj $(LIBS) $(LOPT) $(LFLAGS) -OUT:$(@F)

$(ODIR)rcube.obj : $(TDIR)$(*B).cpp $(TDIR)$(*B).h $(HEADS)
	$(CC) -c $(CFLAGS) $(TDIR)$(*B).cpp -Fo$(ODIR)$(@F)

clean :
	del obj\*.obj

all : $(OUTPUT)
