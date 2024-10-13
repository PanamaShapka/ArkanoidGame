#include "CollisionHandler.h"
#include "Application.h"

namespace ArkanoidGame {

	void CollisionHandler::CheckCollisionBetweenBallAndScreenBorders(Ball& ball)
	{
		// Check x collison
		if (ball.GetPosition().x + ball.GetRadius() > SCREEN_WIDTH) { // Right border
			if (!ball.isCollideWithScreenBorder) {
				ball.MirrorBallSpeed(Ball::BallMovement::RIGHT_MOVEMENT);
			}
			else {
				ball.isCollideWithScreenBorder = true;
			}
		}
		else if (ball.GetPosition().x - ball.GetRadius() < 0.f) { // Left border
			if (!ball.isCollideWithScreenBorder) {
				ball.MirrorBallSpeed(Ball::BallMovement::LEFT_MOVEMENT);
			}
			else {
				ball.isCollideWithScreenBorder = true;
			}
		}
		else {
			ball.isCollideWithScreenBorder = false;
		}

		// Check y collision
		if (ball.GetPosition().y - ball.GetRadius() < 0.f) { // Up border
			if (!ball.isCollideWithScreenBorder) {
				ball.MirrorBallSpeed(Ball::BallMovement::UP_MOVEMENT);
			}
			else {
				ball.isCollideWithScreenBorder = true;
			}
		}
		else if (ball.GetPosition().y + ball.GetRadius() > SCREEN_HEIGHT) { // Down border
			Application::Instance().GetGameState().SetState(GameState::State::GAME_OVER);
		}
		else {
			ball.isCollideWithScreenBorder = false;
		}
	}

	void CollisionHandler::CheckCollisionBetweenBallAndPlatform(Ball& ball, Platform& platform)
	{
		// Check ball collision with platform
		if (!IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::ALL_RECTANGLE)) {
			return; // If ball doesn't collide with platform
		}

		// Check y collision
		if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::UP_SIDE)) {
			if (!ball.isCollideWithRectangle) {
				ball.MirrorBallSpeed(Ball::BallMovement::DOWN_MOVEMENT);
			}
			else { 
				ball.isCollideWithRectangle = true;
			}
		}
		else {
			ball.isCollideWithRectangle = false;
		}

		// Check x collision
		if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::RIGHT_SIDE)) {
			if (!ball.isCollideWithRectangle) {
				ball.MirrorBallSpeed(Ball::BallMovement::LEFT_MOVEMENT);
			}
			else { 
				ball.isCollideWithRectangle = true;
			}
		}
		else if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::LEFT_SIDE)) {
			if (!ball.isCollideWithRectangle) {
				ball.MirrorBallSpeed(Ball::BallMovement::RIGHT_MOVEMENT);
			}
			else { 
				ball.isCollideWithRectangle = true;
			}
		}
		else {
			ball.isCollideWithRectangle = false;
		}
	}

	void CollisionHandler::CheckCollisionBetweenBallAndBlocksSet(Ball& ball, BlocksSet& blocksSet)
	{
		int blockIndex = -1;
		for (Block& currentBlock : blocksSet.GetBlocksSet()) {
			++blockIndex;

			// Check ball collision with block
			if (!IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), currentBlock.GetPosition(), currentBlock.GetSize(), RectangleSide::ALL_RECTANGLE)) {
				continue; // If ball doesn't collide with block
			}

			// Check y collision
			if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), currentBlock.GetPosition(), currentBlock.GetSize(), RectangleSide::UP_SIDE)) {
				if (!ball.isCollideWithRectangle) {
					ball.MirrorBallSpeed(Ball::BallMovement::DOWN_MOVEMENT);
				}
				else {
					ball.isCollideWithRectangle = true;
				}
			}
			else if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), currentBlock.GetPosition(), currentBlock.GetSize(), RectangleSide::DOWN_SIDE)) {
				if (!ball.isCollideWithRectangle) {
					ball.MirrorBallSpeed(Ball::BallMovement::UP_MOVEMENT);
				}
				else {
					ball.isCollideWithRectangle = true;
				}
			}
			else {
				ball.isCollideWithRectangle = false;
			}

			// Check x collision
			if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), currentBlock.GetPosition(), currentBlock.GetSize(), RectangleSide::RIGHT_SIDE)) {
				if (!ball.isCollideWithRectangle) {
					ball.MirrorBallSpeed(Ball::BallMovement::LEFT_MOVEMENT);
				}
				else {
					ball.isCollideWithRectangle = true;
				}
			}
			else if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), currentBlock.GetPosition(), currentBlock.GetSize(), RectangleSide::LEFT_SIDE)) {
				if (!ball.isCollideWithRectangle) {
					ball.MirrorBallSpeed(Ball::BallMovement::RIGHT_MOVEMENT);
				}
				else {
					ball.isCollideWithRectangle = true;
				}
			}
			else {
				ball.isCollideWithRectangle = false;
			}

			// Destroy block
			blocksSet.DestroyBlock(blockIndex);
		}
	}

	bool CollisionHandler::IsCircleCollideWithRectangle(sf::Vector2f circlePosition, float circleRadius, sf::Vector2f rectanglePosition, sf::Vector2f rectangleSize, RectangleSide rectangleSide)
	{
		sf::Vector2f closetRectanglePointToBallCenter;

		// Find closest point on rectangle to the ball center
		switch (rectangleSide)
		{
		case CollisionHandler::RectangleSide::UP_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(circlePosition.x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(circlePosition.y, rectanglePosition.y - rectangleSize.y / 2));
			break;
		}
		case CollisionHandler::RectangleSide::RIGHT_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x + rectangleSize.x / 2, std::min(circlePosition.x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(circlePosition.y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		case CollisionHandler::RectangleSide::DOWN_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(circlePosition.x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y + rectangleSize.y / 2, std::min(circlePosition.y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		case CollisionHandler::RectangleSide::LEFT_SIDE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(circlePosition.x, rectanglePosition.x - rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(circlePosition.y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		case CollisionHandler::RectangleSide::ALL_RECTANGLE:
		{
			closetRectanglePointToBallCenter.x = std::max(rectanglePosition.x - rectangleSize.x / 2, std::min(circlePosition.x, rectanglePosition.x + rectangleSize.x / 2));
			closetRectanglePointToBallCenter.y = std::max(rectanglePosition.y - rectangleSize.y / 2, std::min(circlePosition.y, rectanglePosition.y + rectangleSize.y / 2));
			break;
		};
		default:
			break;
		}

		// Check ball collision with rectangle
		if (std::sqrt(std::powf(closetRectanglePointToBallCenter.x - circlePosition.x, 2) + std::powf(closetRectanglePointToBallCenter.y - circlePosition.y, 2)) < circleRadius) {
			return true;
		}
		else {
			return false;
		}
	}
}
