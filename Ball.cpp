#include "Ball.h"
#include "Application.h"
#include "CollisionHandler.h"

namespace ArkanoidGame {

	Ball::~Ball()
	{

	}

	Ball::Ball(sf::Vector2f position)
	{
		SetStartState();
		SetCircleRelativeOrigin(ball, sf::Vector2f(0.5f, 0.5f));
		ball.setPosition(position);
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

	void Ball::SetState(std::shared_ptr<BallState> state)
	{
		this->state = state;
		ball.setFillColor(state->GetColor());
		ball.setRadius(state->GetRadius());
	}

	void Ball::SetStartState()
	{
		// Set position
		ball.setPosition(sf::Vector2f((float)SCREEN_WIDTH / 2.f, (float)SCREEN_HEIGHT - 175.f));

		// Set ball state
		SetState(std::make_shared<BallStateDefault>());

		// Set random axis speed
		SetRandomAxisSpeed();

		isCollideWithPlatform = false;
		isCollideWithScreenBorders = false;
	}

	void Ball::SetRandomAxisSpeed()
	{
		axisSpeed.x = float(rand() % 99 + 1) / 100.f;
		axisSpeed.y = std::sqrtf(1 - (axisSpeed.x * axisSpeed.x));

		if (rand() % 2) {
			axisSpeed.x *= -1;
		}

		if (rand() % 2) {
			axisSpeed.y *= -1;
		}
	}

	void Ball::ChangeBallMovement(BallMovementX ballMovementX, BallMovementY ballMovementY)
	{
		switch (ballMovementX)
		{
		case ArkanoidGame::Ball::BallMovementX::RIGHT_MOVEMENT:
		{
			if (axisSpeed.x < 0) {
				axisSpeed.x *= -1;
			}
			break;
		}	
		case ArkanoidGame::Ball::BallMovementX::LEFT_MOVEMENT:
		{
			if (axisSpeed.x > 0) {
				axisSpeed.x *= -1;
			}
			break;
		}
		case ArkanoidGame::Ball::BallMovementX::NONE:
			break;
		default:
			break;
		}

		switch (ballMovementY)
		{
		case ArkanoidGame::Ball::BallMovementY::UP_MOVEMENT:
		{
			if (axisSpeed.y > 0) {
				axisSpeed.y *= -1;
			}
			break;
		};
		case ArkanoidGame::Ball::BallMovementY::DOWN_MOVEMENT:
		{
			if (axisSpeed.y < 0) {
				axisSpeed.y *= -1;
			}
			break;
		};
		case ArkanoidGame::Ball::BallMovementY::NONE:
			break;
		default:
			break;
		}
	}
}
