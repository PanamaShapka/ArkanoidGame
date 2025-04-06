#include "BonusObjectSet.h"

namespace ArkanoidGame {

	BonusObjectSet::BonusObjectSet()
	{
		// Init bonus factories
		bonusObjectFactoies.emplace(BonusType::BIGGER_PLATFORM, std::make_unique<BiggerPlatformBonusObjectFactory>());
		bonusObjectFactoies.emplace(BonusType::FIREBALL, std::make_unique<FireballBonusObjectFactory>());
		bonusObjectFactoies.emplace(BonusType::GLASS_BLOCKS, std::make_unique<GlassBlocksBonusObjectFactory>());
		bonusObjectFactoies.emplace(BonusType::MULTI_MINI_BALL, std::make_unique<MutliMiniBallBonusObjectFactory>());
	}

	void BonusObjectSet::Update(float deltaTime)
	{
		std::for_each(bonusObjects.begin(), bonusObjects.end(), [deltaTime](std::shared_ptr<BonusObject> currentBonus) {currentBonus->Update(deltaTime); });
	}

	void BonusObjectSet::Draw(sf::RenderWindow& window)
	{
		std::for_each(bonusObjects.begin(), bonusObjects.end(), [&window](std::shared_ptr<BonusObject> currentBonus) {currentBonus->Draw(window); });
	}

	void BonusObjectSet::SpawnBonusWithChance(sf::Vector2f position)
	{
		if (rand() % 101 <= int(BONUS_SPAWN_CHANCE * 100)) {
			bonusObjects.push_back(bonusObjectFactoies.at(static_cast<BonusType>(rand() % 4))->CreateBonusObject(position));
		}
	}

	void BonusObjectSet::CheckDeletableBonuses()
	{
		for (int i = 0; i < bonusObjects.size(); ++i) {
			if (bonusObjects.at(i)->ShouldDelete()) {
				bonusObjects.erase(bonusObjects.begin() + i);
				i = -1;
			}
		}
	}

	void BonusObjectSet::SetStartState()
	{
		bonusObjects.clear();
	}
}
