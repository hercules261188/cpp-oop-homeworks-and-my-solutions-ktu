VPATH = ./src
CXXFLAGS= -I "./include"

compile&run: PrinterSimulation.o compile
	./bin/PrinterSimulation.exe

PrinterSimulation.o:PrinterSimulation.cpp
	g++ -c $(CXXFLAGS) $< -o ./lib/PrinterSimulation.o

compile:
	g++ ./lib/PrinterSimulation.o -o ./bin/PrinterSimulation.exe