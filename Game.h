#pragma once
#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"
#include "GameState.h"
#include "Block.h"
#include "BlocksSet.h"
#include "CollisionHandler.h"

namespace ArkanoidGame {

	class Game
	{
	public:

		Game();
		~Game();

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);

		Platform& GetPlatform() { return platform; };
		Ball& GetBall() { return ball; }
		GameState& GetState() { return state; };
		BlocksSet& GetBlocksSet() { return blocksSet; }

	private:

		void SetStartState();

	private:
		sf::RectangleShape background;
		Platform platform;
		Ball ball;
		BlocksSet blocksSet;

		float elapsedTimeBetweenAttemerts = 0.f;

		GameState state;

		CollisionHandler collisionHandler;
	};

}

