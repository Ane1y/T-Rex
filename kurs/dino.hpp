#ifndef DINO_HPP
#define DINO_HPP

#include "obstacles.hpp"

class Dino
{
public:
	Dino();
	~Dino() = default;

	void draw(sf::RenderWindow *window);
	void keyboard_input();

	void update(int frames, Obstacles enemy);
	sf::Vector2f getPosition();

private:
	sf::Vector2f position_;
	sf::Vector2f velocity_;
	sf::Vector2f gravity_;
	sf::Texture texture_;
	sf::Sprite dino_;
	sf::IntRect rect_;

	int t_;                     //determine which step is: right or left
	bool jump_;
	bool ground_;

};

#endif
