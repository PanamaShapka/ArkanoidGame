#pragma once
#include "Block.h"

namespace ArkanoidGame {

	class GlassBlock : public Block
	{
	public:

		GlassBlock(const sf::Vector2i positionOnField) : Block(positionOnField) { SetBlockHP(); SetBlockColor(); }

	private:

		void SetBlockHP() override;
		void SetBlockColor() override;
	};

}

