#include "Bonus_Fireball.h"
#include "Application.h"

namespace ArkanoidGame {

	void Bonus_Fireball::Activation()
	{
		Application::Instance().GetGame().GetBall().SetState(std::make_shared<BallStateFireball>());
	}

	void Bonus_Fireball::Deactivation()
	{
		Application::Instance().GetGame().GetBall().SetState(std::make_shared<BallStateDefault>());
	}
}
