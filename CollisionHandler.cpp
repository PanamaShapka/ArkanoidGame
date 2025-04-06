#include "CollisionHandler.h"
#include "Application.h"

namespace ArkanoidGame {

	void CollisionHandler::CheckCollisionBetweenBallAndScreenBorders(Ball& ball)
	{
		// Check x collison
		if (ball.GetPosition().x + ball.GetRadius() > SCREEN_WIDTH) { // Right border
			if (!ball.isCollideWithScreenBorders) {
				ball.ChangeBallMovement(Ball::BallMovementX::LEFT_MOVEMENT, Ball::BallMovementY::NONE);
			}
			else {
				ball.isCollideWithScreenBorders = true;
			}
		}
		else if (ball.GetPosition().x - ball.GetRadius() < 0.f) { // Left border
			if (!ball.isCollideWithScreenBorders) {
				ball.ChangeBallMovement(Ball::BallMovementX::RIGHT_MOVEMENT, Ball::BallMovementY::NONE);
			}
			else {
				ball.isCollideWithScreenBorders = true;
			}
		}
		else {
			ball.isCollideWithScreenBorders = false;
		}

		// Check y collision
		if (ball.GetPosition().y - ball.GetRadius() < 0.f) { // Up border
			if (!ball.isCollideWithScreenBorders) {
				ball.ChangeBallMovement(Ball::BallMovementX::NONE, Ball::BallMovementY::DOWN_MOVEMENT);
			}
			else {
				ball.isCollideWithScreenBorders = true;
			}
		}
		else if (ball.GetPosition().y + ball.GetRadius() > SCREEN_HEIGHT) { // Down border
			Application::Instance().GetGameState().SetState(GameState::State::GAME_OVER);
		}
		else {
			ball.isCollideWithScreenBorders = false;
		}
	}

	void CollisionHandler::CheckCollisionBetweenBallAndPlatform(Ball& ball, Platform& platform)
	{
		// Check ball collision with platform
		if (!IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::ALL_RECTANGLE)) {
			return; // If ball doesn't collide with platform
		}

		bool isXCollision = false;

		// Check x collision
		if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::RIGHT_SIDE)) {
			if (!ball.isCollideWithPlatform) {
				ball.ChangeBallMovement(Ball::BallMovementX::RIGHT_MOVEMENT, Ball::BallMovementY::NONE);
				isXCollision = true;
			}
			else { 
				ball.isCollideWithPlatform = true;
			}
		}
		else if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::LEFT_SIDE)) {
			if (!ball.isCollideWithPlatform) {
				ball.ChangeBallMovement(Ball::BallMovementX::LEFT_MOVEMENT, Ball::BallMovementY::NONE);
				isXCollision = true;
			}
			else { 
				ball.isCollideWithPlatform = true;
			}
		}
		else {
			ball.isCollideWithPlatform = false;
		}

		// Check y collision
		if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::UP_SIDE)) {
			if (!ball.isCollideWithPlatform) {
				if (!isXCollision) {
					ChangeBallAxisSpeedByCollisionPlatform(ball, platform);
				}
				ball.ChangeBallMovement(Ball::BallMovementX::NONE, Ball::BallMovementY::UP_MOVEMENT);
			}
			else {
				ball.isCollideWithPlatform = true;
			}
		}
		else {
			ball.isCollideWithPlatform = false;
		}
	}

	void CollisionHandler::CheckCollisionBetweenBallAndBlocksSet(Ball& ball, BlocksSet& blocksSet)
	{
		if (hittedBlockByBall != nullptr) {
			if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), hittedBlockByBall->GetPosition(), hittedBlockByBall->GetSize(), RectangleSide::ALL_RECTANGLE)) {
				return;
			}
			else {
				hittedBlockByBall = nullptr;
			}
		}
		
		for (auto& currentBlock : blocksSet.blocks) {

			// Check ball collision with block
			if (!IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), currentBlock->GetPosition(), currentBlock->GetSize(), RectangleSide::ALL_RECTANGLE)) {
				continue; // If ball doesn't collide with block
			}

			hittedBlockByBall = currentBlock;

			// If ball collide with block
			if (hittedBlockByBall->GetType() == Block::Type::BasicBlock) {
 
				// Check y collision
				if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), hittedBlockByBall->GetPosition(), hittedBlockByBall->GetSize(), RectangleSide::UP_SIDE)) {
					ball.ChangeBallMovement(Ball::BallMovementX::NONE, Ball::BallMovementY::UP_MOVEMENT);
				}
				else if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), hittedBlockByBall->GetPosition(), hittedBlockByBall->GetSize(), RectangleSide::DOWN_SIDE)) {
					ball.ChangeBallMovement(Ball::BallMovementX::NONE, Ball::BallMovementY::DOWN_MOVEMENT);
				}

				// Check x collision
				if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), hittedBlockByBall->GetPosition(), hittedBlockByBall->GetSize(), RectangleSide::RIGHT_SIDE)) {
					ball.ChangeBallMovement(Ball::BallMovementX::RIGHT_MOVEMENT, Ball::BallMovementY::NONE);
				}
				else if (IsCircleCollideWithRectangle(ball.GetPosition(), ball.GetRadius(), hittedBlockByBall->GetPosition(), hittedBlockByBall->GetSize(), RectangleSide::LEFT_SIDE)) {
					ball.ChangeBallMovement(Ball::BallMovementX::LEFT_MOVEMENT, Ball::BallMovementY::NONE);
				}
			}

			// Hit block
			blocksSet.HitBlock(hittedBlockByBall->GetPositionOnField(), ball);
			return;
		
		}
	}

	void CollisionHandler::CheckCollisionBetweenPlatformAndBonusObjectSet(Platform& platform, BonusObjectSet& bonusObjectSet)
	{
		for (auto& currentBonusObject : bonusObjectSet.GetBonuses()) {

			// Check collision with platform
			if (!IsCircleCollideWithRectangle(currentBonusObject->GetPosition(), currentBonusObject->GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::ALL_RECTANGLE)) {
				continue; // If bonus doesn't collide with platform
			}

			// Check collision with down screen border
			if (currentBonusObject->GetPosition().y - currentBonusObject->GetRadius() > SCREEN_HEIGHT) {
				currentBonusObject->SetShouldDeleteTrue(); // If bonus collide with down screen border
				continue;
			}

			// Activate bonus
			currentBonusObject->Activate();
			
		}

		bonusObjectSet.CheckDeletableBonuses();
		return;
	}

	void CollisionHandler::CheckCollisionBetweenMiniBallsSetAndScreenBorders(MiniBallsSet& miniBallsSet)
	{
		int ballIndex = -1;
		for (Ball& currentMiniBall : miniBallsSet.miniBallsSet) {
			++ballIndex;

			// Check x collison
			if (currentMiniBall.GetPosition().x + currentMiniBall.GetRadius() > SCREEN_WIDTH) { // Right border
				if (!currentMiniBall.isCollideWithScreenBorders) {
					currentMiniBall.ChangeBallMovement(Ball::BallMovementX::LEFT_MOVEMENT, Ball::BallMovementY::NONE);
				}
				else {
					currentMiniBall.isCollideWithScreenBorders = true;
				}
			}
			else if (currentMiniBall.GetPosition().x - currentMiniBall.GetRadius() < 0.f) { // Left border
				if (!currentMiniBall.isCollideWithScreenBorders) {
					currentMiniBall.ChangeBallMovement(Ball::BallMovementX::RIGHT_MOVEMENT, Ball::BallMovementY::NONE);
				}
				else {
					currentMiniBall.isCollideWithScreenBorders = true;					
				}
			}
			else {
				currentMiniBall.isCollideWithScreenBorders = false;
			}

			// Check y collision
			if (currentMiniBall.GetPosition().y - currentMiniBall.GetRadius() < 0.f) { // Up border
				if (!currentMiniBall.isCollideWithScreenBorders) {
					currentMiniBall.ChangeBallMovement(Ball::BallMovementX::NONE, Ball::BallMovementY::DOWN_MOVEMENT);
				}
				else {
					currentMiniBall.isCollideWithScreenBorders = true;
				}
			}
			else if (currentMiniBall.GetPosition().y + currentMiniBall.GetRadius() > SCREEN_HEIGHT) { // Down border
				miniBallsSet.DeleteBall(miniBallsSet.miniBallsSet.begin() + ballIndex);
				--ballIndex;
			}
			else {
				currentMiniBall.isCollideWithScreenBorders = false;
			}
		}
	}

	void CollisionHandler::CheckCollisionBetweenMiniBallsSetAndPlatform(MiniBallsSet& miniBallsSet, Platform& platform)
	{
		for (Ball& currentMiniBall : miniBallsSet.miniBallsSet) {

			// Check ball collision with platform
			if (!IsCircleCollideWithRectangle(currentMiniBall.GetPosition(), currentMiniBall.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::ALL_RECTANGLE)) {
				continue; // If ball doesn't collide with platform
			}

			bool isXCollision = false;

			// Check x collision
			if (IsCircleCollideWithRectangle(currentMiniBall.GetPosition(), currentMiniBall.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::RIGHT_SIDE)) {
				if (!currentMiniBall.isCollideWithPlatform) {
					currentMiniBall.ChangeBallMovement(Ball::BallMovementX::RIGHT_MOVEMENT, Ball::BallMovementY::NONE);
					isXCollision = true;
				}
				else {
					currentMiniBall.isCollideWithPlatform = true;
				}
			}
			else if (IsCircleCollideWithRectangle(currentMiniBall.GetPosition(), currentMiniBall.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::LEFT_SIDE)) {
				if (!currentMiniBall.isCollideWithPlatform) {
					currentMiniBall.ChangeBallMovement(Ball::BallMovementX::LEFT_MOVEMENT, Ball::BallMovementY::NONE);
					isXCollision = true;
				}
				else {
					currentMiniBall.isCollideWithPlatform = true;
				}
			}
			else {
				currentMiniBall.isCollideWithPlatform = false;
			}

			// Check y collision
			if (IsCircleCollideWithRectangle(currentMiniBall.GetPosition(), currentMiniBall.GetRadius(), platform.GetPosition(), platform.GetSize(), RectangleSide::UP_SIDE)) {
				if (!currentMiniBall.isCollideWithPlatform) {
					if (!isXCollision) {
						ChangeBallAxisSpeedByCollisionPlatform(currentMiniBall, platform);
					}
					currentMiniBall.ChangeBallMovement(Ball::BallMovementX::NONE, Ball::BallMovementY::UP_MOVEMENT);
				}
				else {
					currentMiniBall.isCollideWithPlatform = true;
				}
			}
			else {
				currentMiniBall.isCollideWithPlatform = false;
			}
		}
	}

	void CollisionHandler::CheckCollisionBetweenMiniBallsSetAndBlocksSet(MiniBallsSet& miniBallsSet, BlocksSet& blocksSet) 
	{
		int ballIndex = -1;
		for (Ball& currentMiniBall : miniBallsSet.miniBallsSet) {
			++ballIndex;

			for (auto& currentBlock : blocksSet.blocks) {

				// Check ball collision with block
				if (!IsCircleCollideWithRectangle(currentMiniBall.GetPosition(), currentMiniBall.GetRadius(), currentBlock->GetPosition(), currentBlock->GetSize(), RectangleSide::ALL_RECTANGLE)) {
					continue; // If ball doesn't collide with block
				}

				// Hit block
				blocksSet.HitBlock(currentBlock->GetPositionOnField(), currentMiniBall);
				miniBallsSet.DeleteBall(miniBallsSet.miniBallsSet.begin() + ballIndex);
				--ballIndex;
				break;
			}
		}
	}

	void CollisionHandler::ChangeBallAxisSpeedByCollisionPlatform(Ball& ball, Platform& platform)
	{
		float ballAxisSpeedXCoefficient = (ball.GetPosition().x - platform.GetPosition().x + (platform.GetSize().x / 2.f)) / platform.GetSize().x;
		if (ball.axisSpeed.x < 0) { 
			ballAxisSpeedXCoefficient -= 1;
		}

		ball.axisSpeed.x = 0.98f * ballAxisSpeedXCoefficient + 0.01f;
		ball.axisSpeed.y = std::sqrtf(1 - (ball.axisSpeed.x * ball.axisSpeed.x));
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
