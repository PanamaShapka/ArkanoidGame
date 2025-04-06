#include "BonusObject_Fireball.h"
#include "Application.h"

namespace ArkanoidGame {

	void BonusObject_Fireball::Activation()
	{
		Application::Instance().GetGame().GetBonusSet().ActivateBonus(BonusSet::BonusType::FIREBALL);
	}

	void BonusObject_Fireball::SetBonusColor()
	{
		bonusShape.setFillColor(BONUS_FIREBALL_COLOR);
	}
}
