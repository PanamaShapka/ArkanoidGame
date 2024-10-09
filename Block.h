#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class Block : public GameObject
	{
	public:

		Block(sf::Vector2f position);

		void Draw(sf::RenderWindow& window) override;

		sf::Vector2f GetPosition() { return block.getPosition(); };
		sf::Vector2f GetSize() { return block.getSize(); };

	private:

	private:

		sf::RectangleShape block;
	};

}

