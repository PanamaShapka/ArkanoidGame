#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class Ball;

	class Block : public GameObject
	{
	public:

		enum class Type {
			BasicBlock,
			GlassBlock
		};

		Block(const sf::Vector2i positionOnField, Type type);

		void Draw(sf::RenderWindow& window) override;

		void Hit(Ball& ball);
		bool CheckHP();

		sf::Vector2f GetPosition() { return block.getPosition(); };
		sf::Vector2f GetSize() { return block.getSize(); };
		sf::Vector2i GetPositionOnField() { return positionOnField; };
		Type GetType() { return type; }
		int GetMaxHP() { return maxHP; }

	protected:

		virtual void SetBlockHP() = 0;
		virtual void SetBlockColor() = 0;

	protected:

		int maxHP = 1;
		int HP = 0;
		sf::RectangleShape block;
		sf::Vector2i positionOnField;
		Type type;
	};

}

