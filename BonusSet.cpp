#include "BonusSet.h"

namespace ArkanoidGame {

	BonusSet::BonusSet()
	{
		bonuses.emplace_back(std::make_shared<Bonus_BiggerPlatform>());
		bonuses.emplace_back(std::make_shared<Bonus_Fireball>());
		bonuses.emplace_back(std::make_shared<Bonus_GlassBlocks>());
		bonuses.emplace_back(std::make_shared<Bonus_MultiMiniBall>());
	}

	void BonusSet::Update(float deltaTime)
	{
		for (auto& currentBonus : bonuses) {
			currentBonus->Update(deltaTime);
		}
	}

	void BonusSet::SetStartState()
	{
		for (auto& currentBonus : bonuses) {
			if (currentBonus->IsActive()) {
				currentBonus->Deactivate();
			}
		}
	}

	void BonusSet::ActivateBonus(BonusType bonusType)
	{
		bonuses.at(static_cast<int>(bonusType))->Activate();
	}

	std::shared_ptr<Bonus> BonusSet::GetBonus(BonusType bonusType)
	{
		return bonuses.at(static_cast<int>(bonusType));
	}

}