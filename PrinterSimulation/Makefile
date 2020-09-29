VPATH = ./src

compile&run: PrinterSimulation.o compile
	./bin/PrinterSimulation.exe

PrinterSimulation.o:PrinterSimulation.cpp
	g++ -c $< -o ./lib/PrinterSimulation.o

compile:
	g++ ./lib/PrinterSimulation.o -o ./bin/PrinterSimulation.exe