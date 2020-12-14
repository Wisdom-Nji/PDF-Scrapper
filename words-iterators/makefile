LIBS=-L../libs/PDFNetC64/Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -lncurses
INCLUDES=-I../libs/PDFNetC64/Headers
LDFLAGS=-Wl,-rpath,../libs/PDFNetC64/Lib -Wl,-rpath,$$ORIGIN
#LDFLAGS=

all:
	g++ -g main.cxx -o main.o $(LIBS) $(LDFLAGS) $(INCLUDES) -std=c++11
