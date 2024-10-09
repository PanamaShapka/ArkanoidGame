#pragma once
#include "BlocksSet.h"
#include "Ball.h"
#include "Platform.h"

namespace ArkanoidGame {

	class CollisionHandler
	{
	public:

		void CheckCollisionBetweenBallAndScreenBorders(Ball& ball);
		void CheckCollisionBetweenBallAndPlatform(Ball& ball, Platform& platform);
		void CheckCollisionBetweenBallAndBlocksSet(Ball& ball, BlocksSet& blocksSet);

	private:

		enum class RectangleSide {
			UP_SIDE,
			RIGHT_SIDE,
			DOWN_SIDE,
			LEFT_SIDE,
			ALL_RECTANGLE
		};

		bool IsCircleCollideWithRectangle(sf::Vector2f circlePosition, float circleRadius, sf::Vector2f rectanglePosition, sf::Vector2f rectangleSize, RectangleSide rectangleSide);
	};

}


