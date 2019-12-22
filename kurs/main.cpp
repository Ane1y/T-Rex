#include "Game.hpp"

int main()
{
	try
	{
		Game StartGame;
	}

	catch (const std::exception &e)
{
	std::cerr << e.what() << "\n";
	return 2;
}
    return 0;
}