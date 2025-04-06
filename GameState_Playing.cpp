#include "GameState_Playing.h"
#include "Application.h"

namespace ArkanoidGame {

	GameState_Playing::GameState_Playing()
	{
		// Load font
		assert(font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Thin.ttf"));

		// Init texts
		pointsText.setFont(font);
		pointsText.setCharacterSize(30);
		pointsText.setOutlineThickness(1.f);
		pointsText.setOutlineColor(sf::Color::White);
		pointsText.setFillColor(sf::Color::White);
		std::string pointsTextString = "";
		pointsText.setString(pointsTextString);
		pointsText.setPosition(sf::Vector2f(0, SCREEN_HEIGHT - 35.f));
	}

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

		// Update mini balls set
		game.GetMiniBallsSet().Update(deltaTime);

		// Update bonuses
		game.GetBonusObjectSet().Update(deltaTime);
		game.GetBonusSet().Update(deltaTime);

		// Check collisions
		game.GetCollisionHandler().CheckCollisionBetweenBallAndScreenBorders(game.GetBall());
		game.GetCollisionHandler().CheckCollisionBetweenBallAndPlatform(game.GetBall(), game.GetPlatform());
		game.GetCollisionHandler().CheckCollisionBetweenBallAndBlocksSet(game.GetBall(), game.GetBlocksSet());
		game.GetCollisionHandler().CheckCollisionBetweenPlatformAndBonusObjectSet(game.GetPlatform(), game.GetBonusObjectSet());

		if (game.GetBonusSet().GetBonus(BonusSet::BonusType::MULTI_MINI_BALL)->IsActive()) {
			game.GetCollisionHandler().CheckCollisionBetweenMiniBallsSetAndScreenBorders(game.GetMiniBallsSet());
			game.GetCollisionHandler().CheckCollisionBetweenMiniBallsSetAndPlatform(game.GetMiniBallsSet(), game.GetPlatform());
			game.GetCollisionHandler().CheckCollisionBetweenMiniBallsSetAndBlocksSet(game.GetMiniBallsSet(), game.GetBlocksSet());
		}

		// Check block set
		if (game.GetBlocksSet().GetAmountBlocks() == 0) {
			Application::Instance().GetGameState().SetState(GameState::State::GAME_WIN);
		}

		// Update points
		std::string pointsTextString = "Points: " + std::to_string(Application::Instance().GetGame().GetPointsCounter()->GetPoints());
		pointsText.setString(pointsTextString);
	}

	void GameState_Playing::Draw(sf::RenderWindow& window, Game& game)
	{
		// Draw background
		window.draw(game.GetBackground());

		// Draw platform
		game.GetPlatform().Draw(window);

		// Draw bonuses
		game.GetBonusObjectSet().Draw(window);

		// Draw mini balls set
		game.GetMiniBallsSet().Draw(window);

		// Draw ball
		game.GetBall().Draw(window);

		// Draw blocks
		game.GetBlocksSet().Draw(window);

		// Draw texts
		window.draw(pointsText);
	}

	void GameState_Playing::SetStartState(Game& game)
	{
		game.GetBonusSet().SetStartState();
		game.GetBall().SetStartState();
		game.GetPlatform().SetStartState();
		game.GetBlocksSet().SetStartState();
		game.GetBonusObjectSet().SetStartState();
		game.GetPointsCounter()->SetStartState();
	}

}
