#pragma once
#include <cassert>
#include "GameStateData.h"

namespace ArkanoidGame {

	class GameState_MainMenu : public GameStateData
	{
	public:

		GameState_MainMenu();

		void Update(float deltaTime, Game& game) override;
		void Draw(sf::RenderWindow& window, Game& game) override;
		void SetStartState(Game& game) override;

	private:

		enum class Button {
			PLAY_BUTTON = 0,
			SCORE_BUTTON,
			EXIT_BUTTON
		};

		void ChangeButton(Button button);

	private:

		Button button = Button::PLAY_BUTTON;
		bool isKeyPressed = false;

		sf::Font font;

		sf::RectangleShape windowBackgorund;
		sf::RectangleShape background;
		sf::Text titleText;
		sf::Text playText;
		sf::Text scoreText;
		sf::Text exitText;
	};

}

