VPATH=./src
CXXFLAGS=-I "./include"

compile&run: coord box space main compile
	./bin/main.exe

coord: coord.cpp
	g++ -c $(CXXFLAGS) $< -o ./lib/coord.o

box: box.cpp
	g++ -c $(CXXFLAGS) $< -o ./lib/box.o

space: space.cpp
	g++ -c $(CXXFLAGS) $< -o ./lib/space.o

main: main.cpp
	g++ -c $(CXXFLAGS) $< -o ./lib/main.o

compile:
	g++ -std=c++11 ./lib/coord.o ./lib/box.o ./lib/space.o ./lib/main.o -o ./bin/main.exe