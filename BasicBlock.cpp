#include "BasicBlock.h"

namespace ArkanoidGame {

	void BasicBlock::SetBlockHP()
	{
		int currentChanceToImproveBlockHP = 2;
		while (maxHP != MAX_BASIC_BLOCK_HP) {
			if (rand() % currentChanceToImproveBlockHP == 0) {
				++maxHP;
				currentChanceToImproveBlockHP *= 2; // Double reduce the chance
			}
			else {
				break;
			}
		}

		HP = maxHP;
	}

	void BasicBlock::SetBlockColor()
	{
		switch (HP)
		{
		case 1:
		{
			block.setFillColor(BASIC_BLOCK_COLOR_1HP);
			break;
		}
		case 2:
		{
			block.setFillColor(BASIC_BLOCK_COLOR_2HP);
			break;
		}
		case 3:
		{
			block.setFillColor(BASIC_BLOCK_COLOR_3HP);
			break;
		}
		case 4:
		{
			block.setFillColor(BASIC_BLOCK_COLOR_4HP);
			break;
		}
		default:
			break;
		}
	}
}
