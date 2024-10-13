#include "GameState_Playing.h"
#include "Application.h"

namespace ArkanoidGame {

	void GameState_Playing::Update(float deltaTime, Game& game)
	{
		// Check input to move platform
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			game.GetPlatform().Update(Platform::PlatformDirection::LEFT, deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			game.GetPlatform().Update(Platform::PlatformDirection::RIGHT, deltaTime);
		}

		// Update ball
		game.GetBall().Update(deltaTime);

		// Check collisions
		game.GetCollisionHandler().CheckCollisionBetweenBallAndScreenBorders(game.GetBall());
		game.GetCollisionHandler().CheckCollisionBetweenBallAndPlatform(game.GetBall(), game.GetPlatform());
		game.GetCollisionHandler().CheckCollisionBetweenBallAndBlocksSet(game.GetBall(), game.GetBlocksSet());

		// Check block set
		if (game.GetBlocksSet().GetBlocksSet().size() == 0) {
			Application::Instance().GetGameState().SetState(GameState::State::GAME_WIN);
		}
	}

	void GameState_Playing::Draw(sf::RenderWindow& window, Game& game)
	{
		// Draw background
		window.draw(game.GetBackground());

		// Draw platform
		game.GetPlatform().Draw(window);

		// Draw ball
		game.GetBall().Draw(window);

		// Draw blocks
		game.GetBlocksSet().Draw(window);
	}

	void GameState_Playing::SetStartState(Game& game)
	{
		game.GetBall().SetStartState();
		game.GetPlatform().SetStartState();
		game.GetBlocksSet().SetStartState();
	}

}
