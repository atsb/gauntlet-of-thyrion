# makefile to build hexen2 genmodel tool for Win32 using Open Watcom:
#   wmake -f Makefile.wat

# PATH SETTINGS:
!ifndef __UNIX__
PATH_SEP=\
UHEXEN2_TOP=..\..
UTILS_TOP=..
COMMONDIR=$(UTILS_TOP)\common
UHEXEN2_SHARED=$(UHEXEN2_TOP)\common
LIBS_DIR=$(UHEXEN2_TOP)\libs
OSLIBS=$(UHEXEN2_TOP)\oslibs
!else
PATH_SEP=/
UHEXEN2_TOP=../..
UTILS_TOP=..
COMMONDIR=$(UTILS_TOP)/common
UHEXEN2_SHARED=$(UHEXEN2_TOP)/common
LIBS_DIR=$(UHEXEN2_TOP)/libs
OSLIBS=$(UHEXEN2_TOP)/oslibs
!endif

# Names of the binaries
BINARY=genmodel.exe

# Compiler flags
CFLAGS = -zq -wx -bm -bt=nt -5s -sg -otexan -fp5 -fpi87 -ei -j -zp8
!ifdef DEBUG
CFLAGS+= -d2
!else
CFLAGS+= -DNDEBUG=1
!endif
CFLAGS+= -DWIN32_LEAN_AND_MEAN

INCLUDES= -I. -I$(COMMONDIR) -I$(UHEXEN2_SHARED)

#############################################################

.c: $(COMMONDIR);$(UHEXEN2_SHARED)

.c.obj:
	wcc386 $(INCLUDES) $(CFLAGS) -fo=$^@ $<

# Objects
OBJECTS = qsnprint.obj &
	strlcat.obj &
	strlcpy.obj &
	cmdlib.obj &
	q_endian.obj &
	byteordr.obj &
	util_io.obj &
	pathutil.obj &
	scriplib.obj &
	qdir.obj &
	mathlib.obj &
	loadtri.obj &
	token.obj &
	genmodel.obj

all: $(BINARY)

$(BINARY): $(OBJECTS)
	wlink N $@ SYS NT OP q F {$(OBJECTS)}

INCLUDES+= -I"$(OSLIBS)/windows/misc/include"
clean: .symbolic
	rm -f *.obj *.res
distclean: clean .symbolic
	rm -f $(BINARY)
