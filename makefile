#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
LINK.o		=	$(LINK.cc)
LDLIBS		=
LOADLIBS	=
DEBUG		=
DEBUG		=	-g
ZIPCMD	=	zip


TARGET	=	main

WEXECS	=	main.exe

OBJS	=	main.o utf8.o

ZIP_SRC =	main.cc utf8.cc utf8.h

ARCHIVE =	class12.zip

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGET)

zip:
	-$(ZIPCMD) $(ARCHIVE) $(ZIP_SRC)

clean:	
	-$(RM) $(TARGET) $(WEXECS) $(OBJS) $(ARCHIVE)

main:		main.o utf8.o 

##
##      extra rules for cygwin
##
.SUFFIXES:      .cc .exe

.cc.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

