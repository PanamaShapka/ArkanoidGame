#include "BonusObject_GlassBlocks.h"
#include "Application.h"

namespace ArkanoidGame {

	void BonusObject_GlassBlocks::Activation()
	{
		Application::Instance().GetGame().GetBonusSet().ActivateBonus(BonusSet::BonusType::GLASS_BLOCKS);
	}

	void BonusObject_GlassBlocks::SetBonusColor()
	{
		bonusShape.setFillColor(BONUS_GLASS_BLOCKS_PLATFORM_COLOR);
	}
}
