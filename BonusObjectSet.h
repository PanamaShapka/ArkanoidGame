#pragma once
#include <unordered_map>
#include "BonusObjectFactory.h"
#include "Constants.h"

namespace ArkanoidGame {

	class BonusObjectSet : public GameObject
	{
	public:

		BonusObjectSet();
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window) override;
		void SpawnBonusWithChance(sf::Vector2f position);
		void CheckDeletableBonuses();
		void SetStartState();

		std::vector<std::shared_ptr<BonusObject>> GetBonuses() { return bonusObjects; }

	private:

	private:

		enum class BonusType {
			BIGGER_PLATFORM,
			FIREBALL,
			GLASS_BLOCKS,
			MULTI_MINI_BALL
		};

		std::unordered_map<BonusType, std::unique_ptr<BonusFactory>> bonusObjectFactoies;
		std::vector<std::shared_ptr<BonusObject>> bonusObjects;
		
	};

}

