#pragma once
#include <cassert>
#include "GameStateData.h"

namespace ArkanoidGame {

	class GameState_GameWinMenu : public GameStateData
	{
	public:

		GameState_GameWinMenu();

		void Update(float deltaTime, Game& game) override;
		void Draw(sf::RenderWindow& window, Game& game) override;
		void SetStartState(Game& game) override;

	private:

		enum class Button {
			RESUME_BUTTON = 0,
			EXIT_TO_MENU_BUTTON
		};

		void ChangeButton(Button button);

	private:

		Button button = Button::RESUME_BUTTON;
		bool isKeyPressed = false;

		sf::Font font;

		sf::RectangleShape background;
		sf::Text titleText;
		sf::Text resumeText;
		sf::Text exitToMenuText;
		sf::Text pointsText;
		sf::Text bestPointsText;
	};

}

