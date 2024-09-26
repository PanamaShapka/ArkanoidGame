#pragma once
#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"
#include "GameState.h"

namespace ArkanoidGame {

	class Game
	{
	public:

		Game();
		~Game();

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);

		Platform& GetPlatform() { return platform; };
		GameState& GetState() { return state; };

	private:

		void SetStartState();

	private:
		sf::RectangleShape background;
		Platform platform;
		Ball ball;

		float elapsedTimeBetweenAttemerts = 0.f;

		GameState state;
	};

}

