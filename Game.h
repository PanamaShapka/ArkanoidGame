#pragma once
#include <cassert>
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
		
		sf::RectangleShape& GetBackground() { return background; }
		Platform& GetPlatform() { return platform; };
		Ball& GetBall() { return ball; }
		BlocksSet& GetBlocksSet() { return blocksSet; }
		CollisionHandler& GetCollisionHandler() { return collisionHandler; }

	private:

		// Game objects
		sf::RectangleShape background;
		Platform platform;
		Ball ball;
		BlocksSet blocksSet;
		CollisionHandler collisionHandler;
	};

}

