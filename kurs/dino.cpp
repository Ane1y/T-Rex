#include "dino.hpp"

Dino::Dino() : velocity_(0, 0),
               gravity_(0, 0.98),
	             rect_(0, 0, 50, 43),
	             t_(0),
	             jump_(false),
               ground_(true)
{
  texture_.loadFromFile("./Images/dino.png");
	dino_.scale(1.5, 1.5);
  dino_.setTexture(texture_);
  dino_.setTextureRect(rect_);
  dino_.setPosition(50, 550-320);
  position_ = sf::Vector2f(dino_.getPosition());
}

void Dino::draw(sf::RenderWindow *window)
{
  window->draw(dino_);
}

void Dino::keyboard_input()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ground_)
  {
    velocity_.y = -16;
    jump_ = true;
    ground_ = false;
  }
}

void Dino::update(int frames)
{
  position_ += velocity_;
  if (!ground_)
  {
    velocity_ += gravity_;
    if (position_.y >= Constants::jump_height)
    {
      position_.y = Constants::jump_height;
      ground_ = true;
      jump_ = false;
      velocity_.y = 0;
     }
   }

  rect_ = sf::IntRect(t_, 0, 50, 43);

	if (frames % 12 == 0)
	{
		t_ = (t_ + 50) % 100;
	}

  dino_.setTextureRect(rect_);
  dino_.setPosition(position_);
	
	if (ground_)
	{
		velocity_ = sf::Vector2f(0, 0);
	}
}

sf::Vector2f Dino::getPosition()
{
	return position_;
}
