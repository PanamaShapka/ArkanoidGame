#include "Math.h"

namespace ArkanoidGame {

	void SetRectangleRelativeOrigin(sf::RectangleShape& rectangle, sf::Vector2f origin)
	{
		rectangle.setOrigin(origin.x * rectangle.getLocalBounds().width, origin.y * rectangle.getLocalBounds().height);
	}

	void SetCircleRelativeOrigin(sf::CircleShape& circle, sf::Vector2f origin)
	{
		circle.setOrigin(origin.x * circle.getLocalBounds().width, origin.y * circle.getLocalBounds().height);
	}

	void SetRectangleSize(sf::RectangleShape& rectangle, sf::Vector2f size)
	{
		rectangle.setSize(size);
	}

	
}
