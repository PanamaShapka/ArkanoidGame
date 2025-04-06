#pragma once
#include "Block.h"

namespace ArkanoidGame {

	class GlassBlock : public Block
	{
	public:

		GlassBlock(const sf::Vector2i positionOnField) : Block(positionOnField, Type::GlassBlock) { SetBlockHP(); SetBlockColor(); }

	private:

		void SetBlockHP() override;
		void SetBlockColor() override;
	};

}

