a.out : Board.o main.o
	g++ -c Board.o main.o -std=c++11

.c.o:
	g++ -c $< -std=c++11:

Board.o:Board.hpp
main.o:Board.hpp
