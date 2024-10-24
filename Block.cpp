#include "Block.h"

namespace ArkanoidGame {

	Block::Block(const sf::Vector2i positionOnField)
	{
		this->positionOnField = positionOnField;

		// Init rectangle
		block.setSize(BLOCK_SIZE);
		SetRectangleRelativeOrigin(block, sf::Vector2f(0.5f, 0.5f));
		block.setPosition(sf::Vector2f(positionOnField.x * (BLOCK_SIZE.x + 10.f) + (10.f + BLOCK_SIZE.x / 2), positionOnField.y * (BLOCK_SIZE.y + 10.f) + (10.f + BLOCK_SIZE.y / 2)));
	}

	void Block::Draw(sf::RenderWindow& window)
	{
		window.draw(block);
	}

	void Block::Hit()
	{
		--HP;
		SetBlockColor();
	}

	bool Block::CheckHP()
	{
		if (HP == 0) {
			return true;
		}
		else {
			return false;
		}
	}
}



