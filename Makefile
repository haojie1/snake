#SOURCE = $(filter-out main.cpp $(wildcard *.cpp))
CC=g++
SOURCE = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))
LD_LIBRARY_PATH = ./src/lib
INCLUDE_PATH = ./src/include
LIB = -lsdl2main -lsdl2 -lmingw32 -lsdl2_image -lsdl2_ttf
EXE = main.exe

$(EXE): $(OBJ)
	$(CC) $^  -L $(LD_LIBRARY_PATH) $(LIB) -o $@ -g

%.o: %.cpp
	$(CC) -c $< -I $(INCLUDE_PATH) -o $@ -g

.PHONY: clean
clean:
	del /S *.o
