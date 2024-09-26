#include "Game.h"

namespace ArkanoidGame {

	Game::Game()
	{
		// Init background
		background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		background.setFillColor(sf::Color::Black);
		background.setPosition(0.f, 0.f);

		// Set game state
		state.SetState(GameState::State::PLAYING);
	}

	Game::~Game()
	{

	}

	void Game::Update(float deltaTime)
	{
		switch (state.GetState())
		{
		case GameState::State::PLAYING:
		{
			// Check input to move platform
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				platform.Update(Platform::PlatformDirection::RIGHT, deltaTime);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				platform.Update(Platform::PlatformDirection::LEFT, deltaTime);
			}

			// Update ball
			ball.Update(deltaTime);

			break;
		}
		case GameState::State::GAME_OVER:
		{
			if (elapsedTimeBetweenAttemerts < PAUSE_BETWEEN_ATTEMERTS) {
				elapsedTimeBetweenAttemerts += deltaTime;
			}
			else {
				elapsedTimeBetweenAttemerts = 0.f;
				SetStartState();
			}

			break;
		}	
		case GameState::State::MAIN_MENU:
		{
			break;
		}	
		default:
			break;
		}
	}

	void Game::Draw(sf::RenderWindow& window)
	{
		// Draw background
		window.draw(background);

		// Draw platform
		platform.Draw(window);

		// Draw ball
		ball.Draw(window);
	}

	void Game::SetStartState()
	{
		ball.SetStartState();
		platform.SetStartState();

		// Set game state
		state.SetState(GameState::State::PLAYING);
	}
}
