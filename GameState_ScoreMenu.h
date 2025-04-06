#pragma once
#include <cassert>
#include "GameStateData.h"

namespace ArkanoidGame {

	class GameState_ScoreMenu : public GameStateData
	{
	public:

		GameState_ScoreMenu();

		void Update(float deltaTime, Game& game) override;
		void Draw(sf::RenderWindow& window, Game& game) override;
		void SetStartState(Game& game) override;

	private:

	private:

		bool isKeyPressed = false;

		sf::Font font;

		sf::RectangleShape windowBackgorund;
		sf::RectangleShape background;
		sf::Text titleText;
		sf::Text bestScoreText;
		sf::Text exitText;
	};

}

