#pragma once
#include "Block.h"

namespace ArkanoidGame {

	class BasicBlock : public Block
	{
	public:

		BasicBlock(const sf::Vector2i positionOnField) : Block(positionOnField, Type::BasicBlock) { SetBlockHP(); SetBlockColor(); }

	private:

		void SetBlockHP() override;
		void SetBlockColor() override;
	};

}

