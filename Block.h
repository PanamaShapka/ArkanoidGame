#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class Block : public GameObject
	{
	public:

		Block(const sf::Vector2i positionOnField);

		void Draw(sf::RenderWindow& window) override;

		void Hit();
		bool CheckHP();

		sf::Vector2f GetPosition() { return block.getPosition(); };
		sf::Vector2f GetSize() { return block.getSize(); };
		sf::Vector2i GetPositionOnField() { return positionOnField; };

	protected:

		virtual void SetBlockHP() = 0;
		virtual void SetBlockColor() {}

	protected:

		int HP = 1;
		sf::RectangleShape block;
		sf::Vector2i positionOnField;
	};

}

