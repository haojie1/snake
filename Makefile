#SOURCE = $(filter-out main.cpp $(wildcard *.cpp))
OS=WINDOWS
#OS=LINUX

CC=g++
CCFLAGS=-Wall -g
LDFLAGS=-Wl,-rpath,./linuxLib 
SOURCE = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

ifeq ($(OS), LINUX)
	LD_LIBRARY_PATH = ./src/linux/lib
	INCLUDE_PATH = ./src/linux/include
else
	LD_LIBRARY_PATH = ./src/window/lib
	INCLUDE_PATH = ./src/window/include
endif

LIB = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
EXE = main.exe

$(EXE): $(OBJ)
	$(CC) $(CCFLAGS) $(LDFLAGS)  $^  -L $(LD_LIBRARY_PATH) $(LIB) -o $@   -g

%.o: %.cpp
	$(CC) -c $< -I $(INCLUDE_PATH) -o $@ -g

.PHONY: clean
clean:
ifeq ($(OS), LINUX)
	rm *.o
else
	del /S *.o
endif
