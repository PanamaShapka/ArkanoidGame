#include "BonusObject_BiggerPlatform.h"
#include "Application.h"

namespace ArkanoidGame {

	void BonusObject_BiggerPlatform::Activation()
	{
		Application::Instance().GetGame().GetBonusSet().ActivateBonus(BonusSet::BonusType::BIGGER_PLATFORM);
	}

	void BonusObject_BiggerPlatform::SetBonusColor()
	{
		bonusShape.setFillColor(BONUS_BIGGER_PLATFORM_COLOR);
	}
}
