#pragma once
#include "SFML/Graphics.hpp"

namespace ArkanoidGame {

	class Game;

	class GameStateData
	{
	public:

		~GameStateData() = default;
		
		virtual void Update(float deltaTime, Game& game) = 0;
		virtual void Draw(sf::RenderWindow& window, Game& game) = 0;
		virtual void SetStartState(Game& game) = 0;
		
	private:

		
	};

}

