#include "GameState_MainMenu.h"
#include "Application.h"

namespace ArkanoidGame {

	GameState_MainMenu::GameState_MainMenu()
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
		std::string titleTextString = "Arkanoid";
		titleText.setString(titleTextString);
		titleText.setPosition(sf::Vector2f(background.getPosition().x + background.getGlobalBounds().width / 2.f - titleText.getGlobalBounds().width / 2.f, background.getPosition().y + titleText.getGlobalBounds().height / 2.f));

		exitText.setFont(font);
		exitText.setCharacterSize(40);
		exitText.setOutlineThickness(0.5f);
		exitText.setOutlineColor(sf::Color::White);
		exitText.setFillColor(sf::Color::White);
		std::string exitTextString = "Exit";
		exitText.setString(exitTextString);
		exitText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f - exitText.getGlobalBounds().width / 2.f - exitTextString.length() * playText.getOutlineThickness(), background.getPosition().y + background.getGlobalBounds().height - exitText.getGlobalBounds().height * 2.f - 10.f));

		leaderboardText.setFont(font);
		leaderboardText.setCharacterSize(40);
		leaderboardText.setOutlineThickness(0.5f);
		leaderboardText.setOutlineColor(sf::Color::White);
		leaderboardText.setFillColor(sf::Color::White);
		std::string leaderboardTextString = "Leaderboard";
		leaderboardText.setString(leaderboardTextString);
		leaderboardText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f - leaderboardText.getGlobalBounds().width / 2.f, exitText.getPosition().y - 20.f - exitText.getGlobalBounds().height));

		settingsText.setFont(font);
		settingsText.setCharacterSize(40);
		settingsText.setOutlineThickness(0.5f);
		settingsText.setOutlineColor(sf::Color::White);
		settingsText.setFillColor(sf::Color::White);
		std::string settingsTextString = "Settings";
		settingsText.setString(settingsTextString);
		settingsText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f - settingsText.getGlobalBounds().width / 2.f, leaderboardText.getPosition().y - 20.f - leaderboardText.getGlobalBounds().height));

		playText.setFont(font);
		playText.setCharacterSize(40);
		playText.setOutlineThickness(0.5f);
		playText.setOutlineColor(sf::Color::White);
		playText.setFillColor(sf::Color::White);
		std::string playTextString = "Play";
		playText.setString(playTextString);
		playText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f - playText.getGlobalBounds().width / 2.f, settingsText.getPosition().y - 20.f - settingsText.getGlobalBounds().height));
	
		ChangeButton(Button::PLAY_BUTTON);
	}

	void GameState_MainMenu::Update(float deltaTime, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!isKeyPressed) {

				switch (button)
				{
				case Button::PLAY_BUTTON:
				{
					ChangeButton(Button::EXIT_BUTTON);
					break;
				}
				case Button::SETTINGS_BUTTON:
				{
					ChangeButton(Button::PLAY_BUTTON);
					break;
				}
				case Button::LEADERBOARD_BUTTON:
				{
					ChangeButton(Button::SETTINGS_BUTTON);
					break;
				}
				case Button::EXIT_BUTTON:
				{
					ChangeButton(Button::LEADERBOARD_BUTTON);
					break;
				}
				default:
					break;
				}

				isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (!isKeyPressed) {

				switch (button)
				{
				case Button::PLAY_BUTTON:
				{
					ChangeButton(Button::SETTINGS_BUTTON);
					break;
				}
				case Button::SETTINGS_BUTTON:
				{
					ChangeButton(Button::LEADERBOARD_BUTTON); 
					break;
				}
				case Button::LEADERBOARD_BUTTON:
				{
					ChangeButton(Button::EXIT_BUTTON);
					break;
				}
				case Button::EXIT_BUTTON:
				{
					ChangeButton(Button::PLAY_BUTTON);
					break;
				}
				default:
					break;
				}

				isKeyPressed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!isKeyPressed) {

				switch (button)
				{
				case Button::PLAY_BUTTON:
				{
					Application::Instance().GetGameState().SetState(GameState::State::PLAYING);
					break;
				}
				case Button::SETTINGS_BUTTON:
				{
					
					break;
				}
				case Button::LEADERBOARD_BUTTON:
				{
					
					break;
				}
				case Button::EXIT_BUTTON:
				{
					
					break;
				}
				default:
					break;
				}

				isKeyPressed = true;
			}
		}
		else {
			isKeyPressed = false;
		}
	}

	void GameState_MainMenu::Draw(sf::RenderWindow& window, Game& game)
	{
		window.draw(windowBackgorund);
		window.draw(background);
		window.draw(titleText);
		window.draw(playText);
		window.draw(settingsText);
		window.draw(leaderboardText);
		window.draw(exitText);
	}

	void GameState_MainMenu::SetStartState(Game& game)
	{
		// Nothing need
	}

	void GameState_MainMenu::ChangeButton(Button button)
	{
		this->button = button;

		playText.setFillColor(sf::Color::White);
		playText.setOutlineColor(sf::Color::White);

		settingsText.setFillColor(sf::Color::White);
		settingsText.setOutlineColor(sf::Color::White);

		leaderboardText.setFillColor(sf::Color::White);
		leaderboardText.setOutlineColor(sf::Color::White);

		exitText.setFillColor(sf::Color::White);
		exitText.setOutlineColor(sf::Color::White);

		switch (this->button)
		{
		case Button::PLAY_BUTTON:
		{
			playText.setFillColor(sf::Color::Green);
			break;
		}
		case Button::SETTINGS_BUTTON:
		{
			settingsText.setFillColor(sf::Color::Green);
			break;
		}
		case Button::LEADERBOARD_BUTTON:
		{
			leaderboardText.setFillColor(sf::Color::Green);
			break;
		}
		case Button::EXIT_BUTTON:
		{
			exitText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}
	}

}
