#include "game.hpp"

Game::Game() : window_(sf::VideoMode(816, 300), "Flow")
{
  window_.setFramerateLimit(60);
  frames_ = 0;
	loop();
	//gameOver();
}

Game::~Game()
{}

void Game::loop()
{
	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window_.close();
			}
		}
		update();
		render();
		if (intersect())
		{
			gameOver(event);
		}
	}
}

void Game::update()
{
  lvl_.update(frames_);
  enemy_.update(frames_);
  dino_.keyboard_input();
  dino_.update(frames_ , enemy_);
  frames_ = ((frames_ + 1) % 60) + 1;
}

void Game::render()
 {
  window_.clear(sf::Color(200, 200, 200));
	lvl_.draw(&window_);
  enemy_.draw(&window_);
  dino_.draw(&window_);
  window_.display();
 }

bool Game::intersect()
{
	auto dino_Pos = dino_.getPosition();
	auto enemy_Pos = enemy_.getPosition();
	if ((enemy_Pos.x == 50) && (dino_Pos.y > 450-300))
	{
		return true;
	}
	return false;
}

void Game::gameOver(sf::Event event)
{	
	sf::Font font;
	sf::Text str;
	font.loadFromFile("./Font/PixelMiners-KKal.otf");
	str.setFont(font);
	str.setString("Game   over");
	str.setCharacterSize(30);
	str.setFillColor(sf::Color::Black);
	str.setPosition(300, 100);
	window_.clear(sf::Color(200, 200, 200));
	window_.draw(str);
	window_.display();
	
	/*
	if (event.type == sf::Keyboard::R)
	{
		loop();
	} else {
	  */

	system("pause");

}	
