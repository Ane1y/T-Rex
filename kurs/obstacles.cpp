#include "obstacles.hpp"

Obstacles::Obstacles() : rect_(0, 0, 50, 50)
{
	texture_.loadFromFile("./Images/enemies.png");
	enemies_.setTexture(texture_);
	enemies_.setTextureRect(rect_);
	enemies_.setPosition(866, 550 - 325);
	enemies_.scale(1.5, 1.5);

  enemyOnScreen_ = false;
  position_ = sf::Vector2f(enemies_.getPosition());
}

void Obstacles::draw(sf::RenderWindow *window)
{
  window->draw(enemies_);
}

void Obstacles::update(int frames, int acceleration)
{
  int k = randomizer_(0, 3);

  if (!enemyOnScreen_)
  {
    switch (k)
    {
      case 0:
      rect_ = sf::IntRect(0, 0, 50, 50);
      break;

			case 1:
				rect_ = sf::IntRect(50, 0, 50, 50);
				break;

			case 2:
				rect_ = sf::IntRect(0, 50, 50, 50);
				break;

			case 3:
				rect_ = sf::IntRect(50, 50, 50, 50);
				break;
		}
		enemyOnScreen_ = true;
	}

	enemies_.setTextureRect(rect_);

	if (enemyOnScreen_)
	{
		position_.x = position_.x - Constants::movingShift - acceleration;
		enemies_.setPosition(position_);

		if (position_.x <= Constants::min_point)
		{
			enemyOnScreen_ = false;
			enemies_.setPosition(Constants::window_width, 550-325);
		}

	}
	position_ = sf::Vector2f(enemies_.getPosition());
}

sf::Vector2f Obstacles::getPosition()
{
	return position_;
}

