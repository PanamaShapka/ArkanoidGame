#pragma once
#include "Bonus.h"

namespace ArkanoidGame {

	class Bonus_BiggerPlatform : public TimeBonus
	{
	public:

		Bonus_BiggerPlatform() = default;
		~Bonus_BiggerPlatform() = default;

	private:

		void Activation() override;
		void Deactivation() override;

	private:

	};

}

