#include "Bonus_BiggerPlatform.h"
#include "Application.h"

namespace ArkanoidGame {

	void Bonus_BiggerPlatform::Activation()
	{
		Application::Instance().GetGame().GetPlatform().SetState(std::make_shared<PlatformStateBigger>());
	}

	void Bonus_BiggerPlatform::Deactivation()
	{
		Application::Instance().GetGame().GetPlatform().SetState(std::make_shared<PlatformStateDefault>());
	}
}