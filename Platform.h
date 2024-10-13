#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class CollisionHandler;

	class Platform : public GameObject
	{
	public:

		Platform();
		~Platform();

		enum class PlatformDirection {
			RIGHT = 0,
			LEFT,
			NONE
		};

		void Update(PlatformDirection platformDirection, float deltaTime);
		void Draw(sf::RenderWindow& window) override;

		void SetStartState();

		sf::Vector2f GetPosition() { return platform.getPosition(); };
		sf::Vector2f GetSize() { return platform.getSize(); };
		PlatformDirection GetDirection() { return direction; }
		
	private:
		sf::RectangleShape platform;
		PlatformDirection direction;
	};

}

