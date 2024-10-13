#pragma once
#include "SFML/Graphics.hpp"

namespace ArkanoidGame {

	const std::string GAME_NAME = "Arkanoid Ultra Super Extreme Pro Max Extended X";
	const std::string RESOURCES_PATH = "Resources";

	const int SCREEN_WIDTH = 1110;
	const int SCREEN_HEIGHT = 750;

	const float PLATFORM_SPPED = 500.f;
	const float BALL_SPEED = 500.f;

	const float PLATFORM_MOVEMENT_RESTRICTION_DISTANCE_FROM_SCREEN_BORDERS = 10.f; // In pixels

	const float PAUSE_BETWEEN_ATTEMERTS = 1.f; // In seconds

	const sf::Vector2f BLOCK_SIZE(100.f, 25.f);
	const int AMOUNT_OF_BLOCKS = 50;
}