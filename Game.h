#pragma once
#include <cassert>
#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"
#include "GameState.h"
#include "Block.h"
#include "BlocksSet.h"
#include "CollisionHandler.h"
#include "BonusObjectSet.h"
#include "BonusSet.h"
#include "PointsCounter.h"

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
		BonusObjectSet& GetBonusObjectSet() { return bonusObjectSet; }
		BonusSet& GetBonusSet() { return bonusSet; }
		MiniBallsSet& GetMiniBallsSet() { return miniBallsSet; }
		std::shared_ptr<PointsCounter> GetPointsCounter() { return pointsCounter; }

	private:

	private:

		// Game objects
		std::shared_ptr<PointsCounter> pointsCounter = std::make_shared<PointsCounter>(PointsCounter());
		sf::RectangleShape background;
		Platform platform;
		Ball ball;
		BlocksSet blocksSet;
		CollisionHandler collisionHandler;
		BonusObjectSet bonusObjectSet;
		BonusSet bonusSet;
		MiniBallsSet miniBallsSet;
	};

}

