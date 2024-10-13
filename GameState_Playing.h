#pragma once
#include "GameStateData.h"

namespace ArkanoidGame {

	class GameState_Playing : public GameStateData
	{
	public:

		void Update(float deltaTime, Game& game) override;
		void Draw(sf::RenderWindow& window, Game& game) override;
		void SetStartState(Game& game) override;

	private:
	};

}

