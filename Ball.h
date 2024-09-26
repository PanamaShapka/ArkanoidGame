#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"

namespace ArkanoidGame {

	class Ball
	{
	public:

		Ball();

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);

		void SetStartState();

	private:

		void CheckCollisionWithPlatform();
		void CheckCollisionWithScreenBorders();
		
		enum class RectangleSide {
			UP_SIDE,
			RIGHT_SIDE,
			DOWN_SIDE,
			LEFT_SIDE,
			ALL_RECTANGLE
		};

		bool IsBallCollideWithRectangle(sf::Vector2f rectanglePosition, sf::Vector2f rectangleSize, RectangleSide rectangleSide);

		enum class BallMovement {
			RIGHT_MOVEMENT,
			LEFT_MOVEMENT,
			DOWN_MOVEMENT,
			UP_MOVEMENT
		};

		void MirrorBallSpeed(BallMovement currentBallMovement);

	private:

		sf::Vector2f axisSpeed;
		sf::CircleShape ball;
		bool isBallCollideWithScreenBorder = false;
		bool isBallCollideWithRectangle = false;
	};

}

