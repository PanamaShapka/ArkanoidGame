#include "GameState_ScoreMenu.h"
#include "Application.h"

namespace ArkanoidGame {
	GameState_ScoreMenu::GameState_ScoreMenu()
	{
		// Load font
		assert(font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Thin.ttf"));

		// Init backgrounds
		windowBackgorund.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		windowBackgorund.setFillColor(sf::Color::Black);
		windowBackgorund.setPosition(0.f, 0.f);

		background.setSize(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));
		background.setFillColor(sf::Color(0.f, 0.f, 0.f, 127.5f));
		background.setPosition(SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
		background.setOutlineColor(sf::Color::White);
		background.setOutlineThickness(5.f);

		// Init texts
		titleText.setFont(font);
		titleText.setCharacterSize(50);
		titleText.setOutlineThickness(1.f);
		titleText.setOutlineColor(sf::Color::White);
		titleText.setFillColor(sf::Color::White);
		std::string titleTextString = "Score";
		titleText.setString(titleTextString);
		titleText.setPosition(sf::Vector2f(background.getPosition().x + background.getGlobalBounds().width / 2.f - titleText.getGlobalBounds().width / 2.f, background.getPosition().y + titleText.getGlobalBounds().height / 2.f));

		exitText.setFont(font);
		exitText.setCharacterSize(40);
		exitText.setOutlineThickness(0.5f);
		exitText.setOutlineColor(sf::Color::Green);
		exitText.setFillColor(sf::Color::Green);
		std::string exitTextString = "Exit";
		exitText.setString(exitTextString);
		exitText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f - exitText.getGlobalBounds().width / 2.f - exitTextString.length() * exitText.getOutlineThickness(), background.getPosition().y + background.getGlobalBounds().height - exitText.getGlobalBounds().height * 2.f - 10.f));

		bestScoreText.setFont(font);
		bestScoreText.setCharacterSize(40);
		bestScoreText.setOutlineThickness(0.5f);
		bestScoreText.setOutlineColor(sf::Color::White);
		bestScoreText.setFillColor(sf::Color::White);
		std::string leaderboardTextString = "0";
		bestScoreText.setString(leaderboardTextString);
		bestScoreText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f - bestScoreText.getGlobalBounds().width / 2.f, 275.f));
	}

	void GameState_ScoreMenu::Update(float deltaTime, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!isKeyPressed) {
				Application::Instance().GetGameState().SetState(GameState::State::MAIN_MENU);

				isKeyPressed = true;
			}
		}
		else {
			isKeyPressed = false;
		}
	}

	void GameState_ScoreMenu::Draw(sf::RenderWindow& window, Game& game)
	{
		window.draw(windowBackgorund);
		window.draw(background);
		window.draw(titleText);
		window.draw(bestScoreText);
		window.draw(exitText);
	}

	void GameState_ScoreMenu::SetStartState(Game& game)
	{
		std::string leaderboardTextString = "Best score: " + std::to_string(Application::Instance().GetGame().GetPointsCounter()->GetBestPoints());
		bestScoreText.setString(leaderboardTextString);
		bestScoreText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f - bestScoreText.getGlobalBounds().width / 2.f, 275.f));
	}
}
