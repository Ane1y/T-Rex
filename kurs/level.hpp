#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <string>

#include "constants.hpp"

class Level
{
public:
	Level();
	~Level() = default;
	void draw(sf::RenderWindow *window);

	void update(int frames);
	void score();
	int getScore();
	sf::Text getScoreNote() const;

private:
	sf::Texture bg_;
	sf::Sprite background_;
	sf::Vector2f position_;

	sf::Texture cl_;
	sf::Sprite cloud_;
	sf::Vector2f cloudPosition_;

	sf::Font font_;
	int score_;
	sf::Text scoreNote_;

	int cont;

};

#endif