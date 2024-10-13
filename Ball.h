#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class CollisionHandler;

	class Ball : public GameObject
	{
	public:

		friend CollisionHandler;

		~Ball();
		Ball();

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window) override;

		sf::Vector2f GetPosition() { return ball.getPosition(); }
		float GetRadius() { return ball.getRadius(); }

		void SetStartState();

	private:

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
		bool isCollideWithScreenBorder = false;
		bool isCollideWithRectangle = false;
	};

}

