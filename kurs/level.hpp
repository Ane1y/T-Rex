#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <string>
class Level
{
public:
	Level();
	~Level();
	void draw(sf::RenderWindow *window);

	void update(int frames);

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

//	sf::Texture 
};

#endif