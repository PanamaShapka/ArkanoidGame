#include "GlassBlock.h"

namespace ArkanoidGame {

	void GlassBlock::SetBlockHP()
	{
		maxHP = MAX_GLASS_BLOCK_HP;
		HP = maxHP;
	}

	void GlassBlock::SetBlockColor()
	{
		block.setFillColor(GLASS_BLOCK_COLOR_1HP);
	}
}
