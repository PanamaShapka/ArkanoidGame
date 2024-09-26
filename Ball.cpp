#include "Ball.h"
#include "Application.h"

namespace ArkanoidGame {

	Ball::Ball()
	{
		ball.setFillColor(sf::Color::Yellow);
		ball.setRadius(10.f);
		SetCircleRelativeOrigin(ball, sf::Vector2f(0.5f, 0.5f));
		
		SetStartState();
	}

	void Ball::Update(float deltaTime)
	{
		// Set position
		ball.setPosition(sf::Vector2f(ball.getPosition().x + BALL_SPEED * axisSpeed.x * deltaTime, ball.getPosition().y + BALL_SPEED * axisSpeed.y * deltaTime));

		// Check ball collision with screen borders
		CheckCollisionWithScreenBorders();

		// Check ball collision with platform
		CheckCollisionWithPlatform();
	}

	void ArkanoidGame::Ball::Draw(sf::RenderWindow& window)
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

	void Ball::CheckCollisionWithPlatform()
	{
		sf::Vector2f platformPosition = Application::Instance().GetGame().GetPlatform().GetPosition();
		sf::Vector2f platformSize = Application::Instance().GetGame().GetPlatform().GetSize();

		// Check ball collision with platform
		if (!IsBallCollideWithRectangle(platformPosition, platformSize, RectangleSide::ALL_RECTANGLE)) {
			return;
		}

		// Check y collision
		if (IsBallCollideWithRectangle(platformPosition, platformSize, RectangleSide::UP_SIDE)) {
			if (!isBallCollideWithRectangle) {
				MirrorBallSpeed(BallMovement::DOWN_MOVEMENT);
			}
			else {
				isBallCollideWithRectangle = true;
			}	
		}
		else if (IsBallCollideWithRectangle(platformPosition, platformSize, RectangleSide::DOWN_SIDE)) {
			if (!isBallCollideWithRectangle) {
				MirrorBallSpeed(BallMovement::UP_MOVEMENT);
			}
			else {
				isBallCollideWithRectangle = true;
			}	
		}
		else {
			isBallCollideWithRectangle = false;
		}

		// Check x collision
		if (IsBallCollideWithRectangle(platformPosition, platformSize, RectangleSide::RIGHT_SIDE)) {
			if (!isBallCollideWithRectangle) {
				MirrorBallSpeed(BallMovement::LEFT_MOVEMENT);
			}
			else {
				isBallCollideWithRectangle = true;
			}
		}
		else if (IsBallCollideWithRectangle(platformPosition, platformSize, RectangleSide::LEFT_SIDE)) {
			if (!isBallCollideWithRectangle) {
				MirrorBallSpeed(BallMovement::RIGHT_MOVEMENT);
			}
			else {
				isBallCollideWithRectangle = true;
			}
		}
		else {
			isBallCollideWithRectangle = false;
		}
	}

	void Ball::CheckCollisionWithScreenBorders()
	{

		// Check x collison
		if (ball.getPosition().x + ball.getRadius() > SCREEN_WIDTH) { // Right border
			if (!isBallCollideWithScreenBorder) {
				MirrorBallSpeed(BallMovement::RIGHT_MOVEMENT);
			}
			else {
				isBallCollideWithScreenBorder = true;
			}
		}
		else if (ball.getPosition().x - ball.getRadius() < 0.f) { // Left border
			if (!isBallCollideWithScreenBorder) {
				MirrorBallSpeed(BallMovement::LEFT_MOVEMENT);
			}
			else {
				isBallCollideWithScreenBorder = true;
			}
		}
		else {
			isBallCollideWithScreenBorder = false;
		}
		
		// Check y collision
		if (ball.getPosition().y - ball.getRadius() < 0.f) { // Up border
			if (!isBallCollideWithScreenBorder) {
				MirrorBallSpeed(BallMovement::UP_MOVEMENT);
			}
			else {
				isBallCollideWithScreenBorder = true;
			}
		}
		else if (ball.getPosition().y + ball.getRadius() > SCREEN_HEIGHT) { // Down border
			Application::Instance().GetGame().GetState().SetState(GameState::State::GAME_OVER);
		}
		else {
			isBallCollideWithScreenBorder = false;
		}
	}

	bool Ball::IsBallCollideWithRectangle(sf::Vector2f rectanglePosition, sf::Vector2f rectangleSize, RectangleSide rectangleSide)
	{
		sf::Vector2f closetRectanglePointToBallCenter;

		// Find closest point on rectangle to the ball center
		switch (rectangleSide)
		{
		case ArkanoidGame::Ball::RectangleSide::UP_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(ball.getPosition().x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(ball.getPosition().y, rectanglePosition.y - rectangleSize.y / 2));
			break;
		}
		case ArkanoidGame::Ball::RectangleSide::RIGHT_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x + rectangleSize.x / 2, std::min(ball.getPosition().x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(ball.getPosition().y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		case ArkanoidGame::Ball::RectangleSide::DOWN_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(ball.getPosition().x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y + rectangleSize.y / 2, std::min(ball.getPosition().y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		case ArkanoidGame::Ball::RectangleSide::LEFT_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(ball.getPosition().x, rectanglePosition.x - rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(ball.getPosition().y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		case ArkanoidGame::Ball::RectangleSide::ALL_RECTANGLE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(ball.getPosition().x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(ball.getPosition().y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		default:
			break;
		}
		
		// Check ball collision with rectangle
		if (std::sqrt(std::powf(closetRectanglePointToBallCenter.x - ball.getPosition().x, 2) + std::powf(closetRectanglePointToBallCenter.y - ball.getPosition().y, 2)) < ball.getRadius()) {
			return true;
		}
		else {
			return false;
		}

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
