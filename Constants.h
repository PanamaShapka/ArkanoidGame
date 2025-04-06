#pragma once
#include "SFML/Graphics.hpp"

namespace ArkanoidGame {

	const std::string GAME_NAME = "ArkanoiD:";
	const std::string RESOURCES_PATH = "Resources";

	const int SCREEN_WIDTH = 1110;
	const int SCREEN_HEIGHT = 750;

	const float PLATFORM_SPPED = 1000.f; //500
	const float BALL_SPEED = 400.f;
	const float BONUS_SPEED = 100.f;

	const float PLATFORM_MOVEMENT_RESTRICTION_DISTANCE_FROM_SCREEN_BORDERS = 10.f; // In pixels

	const float PAUSE_BETWEEN_ATTEMERTS = 1.f; // In seconds

	const sf::Vector2f BLOCK_SIZE(100.f, 25.f);
	const int AMOUNT_OF_BLOCKS = 50;

	const int MAX_BASIC_BLOCK_HP = 4;
	const int MAX_GLASS_BLOCK_HP = 1;

	const float CHANCE_TO_GET_GLASS_BLOCK = 0.10f;

	// Block colors
	const sf::Color BASIC_BLOCK_COLOR_4HP(7, 35, 51, 255);
	const sf::Color BASIC_BLOCK_COLOR_3HP(26, 63, 85, 255);
	const sf::Color BASIC_BLOCK_COLOR_2HP(108, 147, 170, 255);
	const sf::Color BASIC_BLOCK_COLOR_1HP(171, 197, 213, 255);

	const sf::Color GLASS_BLOCK_COLOR_1HP(247, 142, 255, 255);

	// Points per blocks
	const int POINTS_PER_EACH_1HP_BASIC_BLOCK = 2;
	const int POINTS_PER_EACH_1HP_GLASS_BLOCK = 1;

	// Bonus colors
	const sf::Color BONUS_BIGGER_PLATFORM_COLOR(sf::Color::White);
	const sf::Color BONUS_FIREBALL_COLOR(sf::Color::Red);
	const sf::Color BONUS_GLASS_BLOCKS_PLATFORM_COLOR(247, 142, 255, 255);
	const sf::Color BONUS_MULTI_MINI_BALL_COLOR(255, 165, 0, 255);

	const float BONUS_ACTIVE_TIME = 10.f;
	const float BONUS_SPAWN_CHANCE = 0.5f;
	
}