#pragma once
#include "SFML/Graphics.hpp"

namespace ArkanoidGame {

	const std::string GAME_NAME = "Arkanoid Ultra Super Extreme Pro Max Extended X";
	const std::string RESOURCES_PATH = "Resources";

	const int SCREEN_WIDTH = 1110;
	const int SCREEN_HEIGHT = 750;

	const float PLATFORM_SPPED = 500.f;
	const float BALL_SPEED = 400.f;

	const float PLATFORM_MOVEMENT_RESTRICTION_DISTANCE_FROM_SCREEN_BORDERS = 10.f; // In pixels

	const float PAUSE_BETWEEN_ATTEMERTS = 1.f; // In seconds

	const sf::Vector2f BLOCK_SIZE(100.f, 25.f);
	const int AMOUNT_OF_BLOCKS = 50;

	const int MAX_BASIC_BLOCK_HP = 4;

	const float CHANCE_TO_GET_GLASS_BLOCK = 0.10f;

	// Block colors
	const sf::Color BASIC_BLOCK_COLOR_4HP(1, 42, 27, 255);
	const sf::Color BASIC_BLOCK_COLOR_3HP(0, 86, 59, 255);
	const sf::Color BASIC_BLOCK_COLOR_2HP(3, 192, 60, 255);
	const sf::Color BASIC_BLOCK_COLOR_1HP(172, 225, 175, 255);

	const sf::Color GLASS_BLOCK_COLOR_1HP(255, 255, 255, 255);
	
}