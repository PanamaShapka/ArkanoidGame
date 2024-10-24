#include "GlassBlock.h"

namespace ArkanoidGame {

	void GlassBlock::SetBlockHP()
	{
		HP = 1;
	}

	void GlassBlock::SetBlockColor()
	{
		block.setFillColor(GLASS_BLOCK_COLOR_1HP);
	}
}
