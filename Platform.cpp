#include "Platform.h"

namespace ArkanoidGame {

	Platform::Platform() 
	{
		// Init rectangle
		platform.setFillColor(sf::Color::Magenta);
		platform.setSize(sf::Vector2f(150.f, 10.f));
		SetRectangleRelativeOrigin(platform, sf::Vector2f(0.5f, 0.5f));
		
		SetStartState();
	}

	void Platform::Update(PlatformDirection platformDirection, float deltaTime)
	{
		// Set direction
		direction = platformDirection;

		// Update platform position
		switch (direction)
		{
		case ArkanoidGame::Platform::PlatformDirection::RIGHT: {

			// Check platform collision with right screen border
			if (platform.getPosition().x + (platform.getLocalBounds().width / 2.f) > SCREEN_WIDTH - PLATFORM_MOVEMENT_RESTRICTION_DISTANCE_FROM_SCREEN_BORDERS) {
				// Block the platform movement to the right
				return;
			}

			// Set platform position
			platform.setPosition(sf::Vector2f(platform.getPosition().x + PLATFORM_SPPED * deltaTime, platform.getPosition().y));
			break;
		}
		case ArkanoidGame::Platform::PlatformDirection::LEFT: {

			// Check platform collision with left screen border
			if (platform.getPosition().x - (platform.getLocalBounds().width / 2.f) < 0.f + PLATFORM_MOVEMENT_RESTRICTION_DISTANCE_FROM_SCREEN_BORDERS) {
				// Block the platform movement to the left
				return;
			}

			// Set platform position
			platform.setPosition(sf::Vector2f(platform.getPosition().x - PLATFORM_SPPED * deltaTime, platform.getPosition().y));
			break;
		}
		case ArkanoidGame::Platform::PlatformDirection::NONE: {
			break;
		}
		default:
			break;
		}
	}

	void Platform::Draw(sf::RenderWindow& window)
	{
		window.draw(platform);
	}

	void Platform::SetStartState()
	{
		// Set platform position
		platform.setPosition(sf::Vector2f((float)SCREEN_WIDTH / 2.f, (float)SCREEN_HEIGHT - 75.f));

		// Set platform direction
		direction = PlatformDirection::NONE;

	}
}
