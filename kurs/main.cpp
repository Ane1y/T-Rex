#include "Game.hpp"

int main()
{
	try
	{
		bool newGame = true;
		while (newGame)
		{
			Game StartGame;
			newGame = StartGame.getRestartGame();
		}
  }

	catch (const std::exception &e)
{
	std::cerr << e.what() << "\n";
	return 2;
}
    return 0;
}