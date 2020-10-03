VPATH = ./src

compile&run: main compile
	./bin/main.exe

main:main.cpp
	g++ -c $< -o ./lib/main.o

compile:
	g++ ./lib/main.o -o ./bin/main.exe