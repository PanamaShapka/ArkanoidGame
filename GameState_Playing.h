#pragma once
#include "GameStateData.h"

namespace ArkanoidGame {

	class GameState_Playing : public GameStateData
	{
	public:

		GameState_Playing();

		void Update(float deltaTime, Game& game) override;
		void Draw(sf::RenderWindow& window, Game& game) override;
		void SetStartState(Game& game) override;

	private:

		sf::Font font;

		sf::Text pointsText;
	};

}

