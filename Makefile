CPP = g++
LIBS = -lSDL
BIN = game

game: *.cpp *.h
	$(CPP) -o $(BIN) *.cpp -I . -I /usr/include/SDL $(LIBS)
