#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"

namespace ArkanoidGame {

	class GameObject
	{
	public:

		virtual ~GameObject() = default;

		virtual void Draw(sf::RenderWindow& window) = 0;
	};

}

