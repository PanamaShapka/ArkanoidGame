#pragma once
#include "Constants.h"
#include "Bonus_Fireball.h"
#include "Bonus_BiggerPlatform.h"
#include "Bonus_GlassBlocks.h"
#include "Bonus_MultiMiniBall.h"

namespace ArkanoidGame {

	class BonusSet
	{
	public:

		BonusSet();
		~BonusSet() = default;

		void Update(float deltaTime);
		void SetStartState();

		enum class BonusType {
			BIGGER_PLATFORM,
			FIREBALL,
			GLASS_BLOCKS,
			MULTI_MINI_BALL
		};

		void ActivateBonus(BonusType bonusType);
		std::shared_ptr<Bonus> GetBonus(BonusType bonusType);

	private:

	private:

		std::vector<std::shared_ptr<Bonus>> bonuses;

	};

}

