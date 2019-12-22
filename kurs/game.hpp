#ifndef GAME_HPP
#define GAME_HPP

#include "dino.hpp"
#include "level.hpp"
#include "resultHandler.hpp"

class Game
{
public:
	Game();
	~Game();

	bool loop();
	void update();
	void render();
	bool intersect();
	bool gameOver(sf::Event);
	bool getRestartGame() const;
private:
	sf::RenderWindow window_;
	Dino dino_;
	Level lvl_;
	Obstacles enemy_;
	ResultHandler result_;
	
	int frames;
	bool restartGame;
};

#endif