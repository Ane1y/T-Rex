#include "level.hpp"

Level::Level() :
         	      score_(0),
	              acceleration_(0)
{
  bg_.loadFromFile("./Images/2x-horizon.png");
  bg_.setRepeated(1);
  background_.setTexture(bg_);
  background_.setOrigin(0, 0);
  background_.setPosition(0, 574 - 300);
	position_ = sf::Vector2f(background_.getPosition());

	cl_.loadFromFile("./Images/2x-cloud.png");
	cl_.setRepeated(1);
	cloud_.setTexture(cl_);
	cloud_.setOrigin(0, 200);
	cloud_.setPosition(0, 200);
  cloudPosition_ = sf::Vector2f(background_.getPosition());

	font_.loadFromFile("./Font/PixelMiners-KKal.otf");
	scoreNote_.setFont(font_);
	scoreNote_.setString("0");
	scoreNote_.setCharacterSize(20);
	scoreNote_.setFillColor(sf::Color(83, 83, 83));
	scoreNote_.setPosition(750, 5);
}

void Level::draw(sf::RenderWindow *window)
{	
  window->draw(background_);
	window->draw(cloud_);
	window->draw(scoreNote_);
}

void Level::update(int frames)
{
	//background update

  position_.x = position_.x - Constants::movingShift - acceleration_;
  if (position_.x < -2200)
  {
    position_.x = 0;
  }
  background_.setPosition(position_);
  position_ = sf::Vector2f(background_.getPosition());
  
	//clouds update
	cloudPosition_.x = cloudPosition_.x - 4;
	cloud_.setPosition(cloudPosition_);

	if (cloudPosition_.x <= Constants::min_point)
	{
		int height = randomizer_(0, 120);
		cloud_.setPosition(866, 350 - height);
	}
	cloudPosition_ = sf::Vector2f(cloud_.getPosition());

	score();
	increaseAcceleration();
}

void Level::score()
{
	score_++;
	scoreNote_.setString(std::to_string(score_ / 10));
}

void Level::increaseAcceleration()
{
	int n = score_;
	n = n / 1000;
	acceleration_ = n;
}

int Level::getScore() const
{
	return score_ / 10;
}

sf::Text Level::getScoreNote() const
{
	return scoreNote_;
}

int Level::getAcceleration() const
{
	return acceleration_;
}

