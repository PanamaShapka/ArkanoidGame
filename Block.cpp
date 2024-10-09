#include "Block.h"

namespace ArkanoidGame {

	Block::Block(sf::Vector2f position)
	{
		// Init rectangle
		block.setFillColor(sf::Color::White);
		block.setSize(BLOCK_SIZE);
		SetRectangleRelativeOrigin(block, sf::Vector2f(0.5f, 0.5f));
		block.setPosition(position);
	}

	void Block::Draw(sf::RenderWindow& window)
	{
		window.draw(block);
	}
}



