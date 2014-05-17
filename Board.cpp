#include "Board.hpp"

const bool Board::Grids::get_status()
{
	return status;
}

void Board::Grids::set_status(bool status_)
{
	status = status_;
}

const bool  Board::Grids::next_status(Board &parent)
{{{
	int neighbor_sum = 0;
	int status_ = status;

	for(int i = -1; i <= 1; i++)
	{
		//to adge, to corner
		if(x + i < 0 || x + i > parent.old_boards.size())
		{
			continue;
		}
		for(int j = -1; j <= 1; j++)
		{
			//to adge, to corner
			if(y + j < 0 || (i == 0 && j == 0) || y + j > parent.old_boards.size())
			{
				continue;
			}
			neighbor_sum += parent.old_boards.vec[x + i][y + j].get_status();
		}
	}

	//birth condition
	if(neighbor_sum == 3)
	{
		status_ = 1;
	}
	
	//survive condition
	else if(neighbor_sum == 2 && status == 1)
	{
		status_ = 1;
	}

	else
	{
		status_ = 0;
	}

	return status_;
}}}

const void Board::print_board()
{{{
	for(int i = 0; i < boards.size(); i++)
	{
		for(int j = 0; j < boards.size(); j++)
		{
			std::cout << boards.vec[i][j].get_status() << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}}}

//return change(=1) or not(=0) 
bool Board::next_board()
{{{
	for(int i = 0; i < old_boards.size(); i++)
	{
		for(int j = 0; j < old_boards.size(); j++)
		{
			boards.vec[i][j].status = old_boards.vec[i][j].next_status(*this);
		}
	}

	//compare
	bool is_changed = 0;
	for(int i = 0; !is_changed && i < old_boards.size(); i++)
	{
		for(int j = 0; !is_changed && j < old_boards.size(); j++)
		{
			if(boards.vec[i][j].status != old_boards.vec[i][j].status)
			{
				is_changed = 1;
			}
		}
	}
	
	//old -> next_old
	for(int i = 0; i < old_boards.size(); i++)
	{
		for(int j = 0; j < old_boards.size(); j++)
		{
			old_boards.vec[i][j].status =  boards.vec[i][j].status;
		}
	}

	return is_changed;
}}}
