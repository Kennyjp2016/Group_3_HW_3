SHELL = /bin/bash
CC = g++
CFLAGS = -g -Wall
OUTP = main.o SearchBenchMark.o TicTacToe.o SortBenchMark.o LoShuMagicSquare.o util.o

runMe: $(OUTP)
		g++ $(CFLAGS) -o runMe $(OUTP)

main.o: main.cpp questions.h util.h
		g++ -c main.cpp

LoShuMagicSquare.o: LoShuMagicSquare.cpp util.h
	g++ -c LoShuMagicSquare.cpp

SortBenchMark.o: SortBenchMark.cpp util.h
	g++ -c SortBenchMark.cpp

SearchBenchMark.o: SearchBenchMark.cpp util.h
	g++ -c SearchBenchMark.cpp

TicTacToe.o: TicTacToe.cpp util.h
	g++ -c TicTacToe.cpp

util.o: util.cpp
	g++ -c util.cpp

clean:
	rm runMe $(OUTP) *.txt
