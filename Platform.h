#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"

namespace ArkanoidGame {

	class Platform
	{
	public:

		Platform();

		enum class PlatformDirection {
			RIGHT = 0,
			LEFT,
			NONE
		};

		void Update(PlatformDirection platformDirection, float deltaTime);
		void Draw(sf::RenderWindow& window);

		void SetStartState();

		sf::Vector2f GetPosition() { return platform.getPosition(); };
		sf::Vector2f GetSize() { return platform.getSize(); };
		
	private:
		sf::RectangleShape platform;
		PlatformDirection direction;
	};

}

