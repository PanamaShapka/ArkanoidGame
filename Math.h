#pragma once
#include <SFML/Graphics.hpp>

namespace ArkanoidGame {

	void SetRectangleRelativeOrigin(sf::RectangleShape& rectangle, sf::Vector2f origin);
	void SetCircleRelativeOrigin(sf::CircleShape& circle, sf::Vector2f origin);
	void SetRectangleSize(sf::RectangleShape& rectangle, sf::Vector2f size);

	
}

