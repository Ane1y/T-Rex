#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP

#include <SFML/Graphics.hpp>
#include "constants.hpp"

class Obstacles
{
public:
	Obstacles();
	~Obstacles() = default;
	void draw(sf::RenderWindow *window);
	void update(int, int);
	sf::Vector2f getPosition();

private:
	sf::Texture texture_;
	sf::Sprite enemies_;
	sf::IntRect rect_;
	sf::Vector2f position_;
	bool enemyOnScreen_;
}; 
#endif
