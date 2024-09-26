#pragma once
#include "SFML/Graphics.hpp"

namespace ArkanoidGame {

	const std::string GAME_NAME = "ArkanoidUltra";
	const std::string RESOURCES_PATH = "Resources";

	const int SCREEN_WIDTH = 1100;
	const int SCREEN_HEIGHT = 750;

	const float PLATFORM_SPPED = 500.f;
	const float BALL_SPEED = 250.f;

	const float PLATFORM_MOVEMENT_RESTRICTION_DISTANCE_FROM_SCREEN_BORDERS = 10.f; // In pixels

	const float PAUSE_BETWEEN_ATTEMERTS = 5.f;
}