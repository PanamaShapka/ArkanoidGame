#include "Bonus.h"

namespace ArkanoidGame {

	void TimeBonus::Update(float deltaTime)
	{
		if (isActive) {
			elapsedActiveTime += deltaTime;
			if (elapsedActiveTime >= BONUS_ACTIVE_TIME) {
				Deactivate();
			}
		}
	}

	void TimeBonus::Activate()
	{
		if (isActive) {
			elapsedActiveTime -= 10.f;
		}
		else {
			isActive = true;
			elapsedActiveTime = 0.f;
			Activation();
		}
	}

	void TimeBonus::Deactivate()
	{
		isActive = false;
		Deactivation();
	}

	
	void ActivatingBonus::Update(float deltaTime)
	{
		/**/
	}

	void ActivatingBonus::Activate()
	{
		isActive = true;
		Activation();
	}

	void ActivatingBonus::Deactivate()
	{
		isActive = false;
		Deactivation();
	}

}
