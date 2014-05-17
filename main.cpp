#include "Board.hpp"

int main()
{
	std::string str;
	str = "0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ";
	Board test(str);

	while(1)
	{
		test.print_board();
		if(!test.next_board())
		{
			test.print_board();
			std::cout << "This World is end" << std::endl;
			break;
		}
	}
}
