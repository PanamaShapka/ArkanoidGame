#include "Game.h"

namespace ArkanoidGame {

	Game::Game()
	{
		// Init background
		background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		background.setFillColor(sf::Color::Black);
		background.setPosition(0.f, 0.f);
	}

	Game::~Game()
	{

	}
}
