CXX = g++
SRC = main.cpp gameobject.cpp background.cpp camera.cpp
OBJ = main.o gameobject.o background.o camera.o
INCLUDE = "C:\Library\SDL2-2.26.3\x86_64-w64-mingw32\include"
LIB = "C:\Library\SDL2-2.26.3\x86_64-w64-mingw32\lib"
EXE = main.exe
FLAGS = -std=c++11 -Wall -pedantic

all: $(EXE)

$(EXE):$(OBJ)
	$(CXX) $(OBJ) -L$(LIB) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o $(EXE)
  
$(OBJ):$(SRC)
	$(CXX) $(FLAGS) -I$(INCLUDE) -c $(SRC)

clean:
	del $(OBJ) $(EXE)