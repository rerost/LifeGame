#ifndef a20140517
#define a20140517

//#define def_board 10
const int def_board = 5;

#include<iostream>
#include<string>

template<typename T, int SIZE>
class MyVector
{
public:
	//Body
	T vec[SIZE][SIZE];

	MyVector()
	{
		for(int i = 0; i < SIZE; i++)
		{
			for(int j = 0; j < SIZE; j++)
			{
				vec[i][j].x = i;
				vec[i][j].y = j;
			}
		}
	}

	constexpr int size()
	{
		return SIZE;
	}
};

class Board
{	
public:
	class Grids
	{
	public:
		int x;
		int y;
		bool status;
		
		Grids() {};
		Grids(int x_, int y_) : x(x_), y(y_) {}
		const bool get_status();
		void set_status(bool);
		const bool next_status(Board &parent);
	};

	MyVector< Grids, def_board > boards;
	MyVector< Grids, def_board > old_boards;

	Board(const std::string str)
	{
		for(int i = 0; i < old_boards.size(); i++)
		{
			for(int j = 0; j < old_boards.size(); j++)
			{
				int k = i * old_boards.size() + j;
				k = 2 * k;

				boards.vec[i][j].set_status((int)str[k] - '0' );
				old_boards.vec[i][j].set_status((int)str[k] - '0' );
			}
		}
	}

	const void print_board();
	bool next_board();
};

#endif	
