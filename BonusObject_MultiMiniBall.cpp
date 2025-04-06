#include "BonusObject_MultiMiniBall.h"
#include "Application.h"

namespace ArkanoidGame {

	void BonusObject_MultiMiniBall::Activation()
	{
		Application::Instance().GetGame().GetBonusSet().ActivateBonus(BonusSet::BonusType::MULTI_MINI_BALL);
	}

	void BonusObject_MultiMiniBall::SetBonusColor()
	{
		bonusShape.setFillColor(BONUS_MULTI_MINI_BALL_COLOR);
	}
}


