#include "GameState_GameWinMenu.h"
#include "Application.h"

namespace ArkanoidGame {

	GameState_GameWinMenu::GameState_GameWinMenu()
	{
		// Load font
		assert(font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Thin.ttf"));

		// Init background
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
		std::string gameOverTextString = "You win";
		titleText.setString(gameOverTextString);
		titleText.setPosition(sf::Vector2f(background.getPosition().x + background.getGlobalBounds().width / 2.f - titleText.getGlobalBounds().width / 2.f, background.getPosition().y + titleText.getGlobalBounds().height / 2.f));

		exitToMenuText.setFont(font);
		exitToMenuText.setCharacterSize(40);
		exitToMenuText.setOutlineThickness(0.5f);
		exitToMenuText.setOutlineColor(sf::Color::White);
		exitToMenuText.setFillColor(sf::Color::White);
		std::string exitToMenuTextString = "Exit to menu";
		exitToMenuText.setString(exitToMenuTextString);
		exitToMenuText.setPosition(sf::Vector2f(background.getPosition().x + background.getGlobalBounds().width / 2.f - exitToMenuText.getGlobalBounds().width / 2.f, background.getPosition().y + background.getGlobalBounds().height - exitToMenuText.getGlobalBounds().height * 2.f - 10.f));


		resumeText.setFont(font);
		resumeText.setCharacterSize(40);
		resumeText.setOutlineThickness(0.5f);
		resumeText.setOutlineColor(sf::Color::White);
		resumeText.setFillColor(sf::Color::White);
		std::string resumeTextString = "Resume";
		resumeText.setString(resumeTextString);
		resumeText.setPosition(sf::Vector2f(background.getPosition().x + background.getGlobalBounds().width / 2.f - resumeText.getGlobalBounds().width / 2.f, exitToMenuText.getPosition().y - 20.f - exitToMenuText.getGlobalBounds().height));
	}

	void GameState_GameWinMenu::Update(float deltaTime, Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!isKeyPressed) {

				switch (button)
				{
				case Button::RESUME_BUTTON:
				{
					ChangeButton(Button::EXIT_TO_MENU_BUTTON);
					break;
				}
				case Button::EXIT_TO_MENU_BUTTON:
				{
					ChangeButton(Button::RESUME_BUTTON);
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
				case Button::RESUME_BUTTON:
				{
					ChangeButton(Button::EXIT_TO_MENU_BUTTON);
					break;
				}
				case Button::EXIT_TO_MENU_BUTTON:
				{
					ChangeButton(Button::RESUME_BUTTON);
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
				case Button::RESUME_BUTTON:
				{
					Application::Instance().GetGameState().SetState(GameState::State::PLAYING);
					break;
				}
				case Button::EXIT_TO_MENU_BUTTON:
				{
					Application::Instance().GetGameState().SetState(GameState::State::MAIN_MENU);
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

	void GameState_GameWinMenu::Draw(sf::RenderWindow& window, Game& game)
	{
		// Draw background
		window.draw(game.GetBackground());

		// Draw platform
		game.GetPlatform().Draw(window);

		// Draw ball
		game.GetBall().Draw(window);

		// Draw blocks
		game.GetBlocksSet().Draw(window);

		// Draw background
		window.draw(background);

		// Draw texts
		window.draw(titleText);
		window.draw(resumeText);
		window.draw(exitToMenuText);
	}

	void GameState_GameWinMenu::SetStartState(Game& game)
	{
		ChangeButton(Button::RESUME_BUTTON);
	}

	void GameState_GameWinMenu::ChangeButton(Button button)
	{
		this->button = button;

		resumeText.setFillColor(sf::Color::White);
		resumeText.setOutlineColor(sf::Color::White);

		exitToMenuText.setFillColor(sf::Color::White);
		exitToMenuText.setOutlineColor(sf::Color::White);

		switch (this->button)
		{
		case Button::RESUME_BUTTON:
		{
			resumeText.setFillColor(sf::Color::Green);
			break;
		}
		case Button::EXIT_TO_MENU_BUTTON:
		{
			exitToMenuText.setFillColor(sf::Color::Green);
			break;
		}
		default:
			break;
		}
	}
}
