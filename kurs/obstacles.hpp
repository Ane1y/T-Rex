#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP

#include <SFML/Graphics.hpp>

#include <time.h>
#include <iostream>

class Obstacles
{
public:
	Obstacles();
	~Obstacles();
	void draw(sf::RenderWindow *window);
	void update(int frames);
	sf::Vector2f getPosition();

private:
	sf::Texture texture_;
	sf::Sprite enemies_;
	sf::IntRect rect_;
	sf::Vector2f position_;
	bool enemyOnScreen_;
}; 
#endif
