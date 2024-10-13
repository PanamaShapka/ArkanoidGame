#include "Ball.h"
#include "Application.h"
#include "CollisionHandler.h"

namespace ArkanoidGame {

	Ball::~Ball()
	{

	}

	Ball::Ball()
	{
		ball.setFillColor(sf::Color::Yellow);
		ball.setRadius(10.f);
		SetCircleRelativeOrigin(ball, sf::Vector2f(0.5f, 0.5f));
		
		SetStartState();
	}

	void Ball::Update(float deltaTime)
	{
		// Update position
		ball.setPosition(sf::Vector2f(ball.getPosition().x + BALL_SPEED * axisSpeed.x * deltaTime, ball.getPosition().y + BALL_SPEED * axisSpeed.y * deltaTime));
	}

	void Ball::Draw(sf::RenderWindow& window)
	{
		window.draw(ball);
	}


	void Ball::SetStartState()
	{
		// Set ball position
		ball.setPosition(sf::Vector2f((float)SCREEN_WIDTH / 2.f, (float)SCREEN_HEIGHT - 175.f));

		// Set ball flying angle
		axisSpeed = { ((rand() % 199 - 99) / 100.f), 1.f };
	}

	void Ball::MirrorBallSpeed(BallMovement currentBallMovement)
	{
		// Check current ball movement
		switch (currentBallMovement)
		{
		case ArkanoidGame::Ball::BallMovement::RIGHT_MOVEMENT:
		{
			if (axisSpeed.x > 0) {
				axisSpeed.x *= -1;
			}
			break;
		}	
		case ArkanoidGame::Ball::BallMovement::LEFT_MOVEMENT:
		{
			if (axisSpeed.x < 0) {
				axisSpeed.x *= -1;
			}
			break;
		}
		case ArkanoidGame::Ball::BallMovement::DOWN_MOVEMENT:
		{
			if (axisSpeed.y > 0) {
				axisSpeed.y *= -1;
			}
			break;
		}
		case ArkanoidGame::Ball::BallMovement::UP_MOVEMENT:
		{
			if (axisSpeed.y < 0) {
				axisSpeed.y *= -1;
			}
			break;
		}
		default:
			break;
		}
	}
}
