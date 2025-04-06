#pragma once
#include "Bonus.h"

namespace ArkanoidGame {

	class Bonus_Fireball : public TimeBonus
	{
	public:

		Bonus_Fireball() = default;
		~Bonus_Fireball() = default;

	private:

		void Activation() override;
		void Deactivation() override;

	private:

	};

}
