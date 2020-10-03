VPATH=./src
CXXFLAGS=-I "./include"

compile&run: image main compile
	./bin/main.exe image1.bin image2.bin image1.txt image2.txt

image: image.cpp
	g++ -c $(CXXFLAGS) $< -o ./lib/image.o

main: main.cpp
	g++ -c $(CXXFLAGS) $< -o ./lib/main.o

compile:
	g++ -std=c++11 ./lib/image.o ./lib/main.o -o ./bin/main.exe