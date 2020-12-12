LIBS=-LPDFNetC64/Lib -lPDFNetC -lstdc++ -lpthread -lm -lc
INCLUDES=-IPDFNetC64/Headers
LDFLAGS=-Wl,-rpath,PDFNetC64/Lib -Wl,-rpath,$$ORIGIN

all:
	g++ -g main.cxx -o main.o $(LIBS) $(LDFLAGS) $(INCLUDES) -std=c++11
