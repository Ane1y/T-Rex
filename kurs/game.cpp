#include "game.hpp"

Game::Game() :
	window_(sf::VideoMode(816, 300), "Flow"),
	result_()
{
	window_.setFramerateLimit(60);
	frames_ = 0;
	if (!loop())
	{
		loop();
	}
}

Game::~Game()
{}

bool Game::loop()
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
			if (gameOver(event))
			{
				window_.close();
			}
			else
				return false;
		}
	}
	return false;
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
	
	int dino_x = dino_Pos.x;
	int dino_y = dino_Pos.y;

	int enemy_x = enemy_Pos.x;
	int enemy_y = enemy_Pos.y;

	if ((abs(enemy_Pos.x - dino_Pos.x) < 6) && (dino_Pos.y > 450-300))
	{
		return true;
	}
	return false;
}

bool Game::gameOver(sf::Event event)
{	
	sf::Font font;
	sf::Text str;
	sf::Text score = lvl_.getScoreNote();

	font.loadFromFile("./Font/PixelMiners-KKal.otf");

	str.setFont(font);
	str.setString("Game   over");
	str.setCharacterSize(30);
	str.setFillColor(sf::Color(83, 83, 83));
	str.setPosition(300, 100);

	score.setFont(font);
	score.setCharacterSize(20);
	score.setPosition(750, 5);

	window_.clear(sf::Color(200, 200, 200));

	window_.draw(str);
	window_.draw(score);
	window_.display();
	
	result_.update(lvl_.getScore());
	result_.print();

	char key;
	std::cin >> key;
	if (key == 'R')
	{
		return false;
	}
	return true;
}

bool Game::getRestartGame() const
{
	return restartGame;
}
