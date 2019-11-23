#ifndef GAME_HPP
#define GAME_HPP
#include "dino.hpp"
#include "level.hpp"

class Game
{
public:
	Game();
	~Game();
	void loop();
	void update();
	void render();
	bool intersect();
	void gameOver(sf::Event);

private:
	sf::RenderWindow window_;
	Dino dino_;
	Level lvl_;
	Obstacles enemy_;
	int frames_;
};

#endif