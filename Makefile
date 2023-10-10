output: main.o LinkedList.o Index.o Functions.o Calculator.o
	g++ main.o LinkedList.o Index.o Functions.o Calculator.o -o TurnOnCalculator

main.o: main.cpp
	g++ -c main.cpp

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp Sci_Calcu.h

Index.o: Index.cpp
	g++ -c Index.cpp Sci_Calcu.h

Functions.o: Functions.cpp
	g++ -c Functions.cpp Sci_Calcu.h

Calculator.o: Calculator.cpp
	g++ -c Calculator.cpp Sci_Calcu.h
