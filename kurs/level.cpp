#include "level.hpp"

Level::Level()
{
  bg_.loadFromFile("./Images/2x-horizon.png");
  bg_.setRepeated(1);
  background_.setTexture(bg_);
  background_.setOrigin(0, 0);
  background_.setTextureRect(sf::IntRect(0, 0, 3000, 26));
  background_.setPosition(0, 574 - 300);
	position_ = sf::Vector2f(background_.getPosition());

	cl_.loadFromFile("./Images/2x-cloud.png");
	cl_.setRepeated(1);
	cloud_.setTexture(cl_);
	cloud_.setOrigin(0, 200);
//	cloud_.setTextureRect(sf::IntRect(0, 0, 1632, 26));
	cloud_.setPosition(0, 200);
  cloudPosition_ = sf::Vector2f(background_.getPosition());

	font_.loadFromFile("./Font/PixelMiners-KKal.otf");
	scoreNote_.setFont(font_);
	scoreNote_.setString("0");
	scoreNote_.setCharacterSize(20);
	scoreNote_.setFillColor(sf::Color::Black);
	scoreNote_.setPosition(700, 50);
	score_ = 0;	

	srand(NULL);
}

Level::~Level() {}

void Level::draw(sf::RenderWindow *window)
{	
  window->draw(background_);
	window->draw(cloud_);
	window->draw(scoreNote_);
}

void Level::update(int frames)
{
	//background update
  position_.x = position_.x - 4;
  if (position_.x == -2300)
  {
    position_.x = 0;
  }
  background_.setPosition(position_);
  position_ = sf::Vector2f(background_.getPosition());
  
	//clouds update
	cloudPosition_.x = cloudPosition_.x - 4;
	cloud_.setPosition(cloudPosition_);

	if (cloudPosition_.x <= -50)
	{
		int scale = rand() % 100;
		cloud_.setPosition(866, 350 - scale);
	}
	cloudPosition_ = sf::Vector2f(cloud_.getPosition());

		score_++;
  	scoreNote_.setString(std::to_string(score_ / 10));
}

