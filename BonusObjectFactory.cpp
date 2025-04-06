#include "BonusObjectFactory.h"

namespace ArkanoidGame {


	std::shared_ptr<BonusObject> BiggerPlatformBonusObjectFactory::CreateBonusObject(const sf::Vector2f& position)
	{
		return std::make_shared<BonusObject_BiggerPlatform>(position);
	}

	std::shared_ptr<BonusObject> FireballBonusObjectFactory::CreateBonusObject(const sf::Vector2f& position)
	{
		return std::make_shared<BonusObject_Fireball>(position);
	}

	std::shared_ptr<BonusObject> GlassBlocksBonusObjectFactory::CreateBonusObject(const sf::Vector2f& position)
	{
		return std::make_shared<BonusObject_GlassBlocks>(position);
	}

	std::shared_ptr<BonusObject> MutliMiniBallBonusObjectFactory::CreateBonusObject(const sf::Vector2f& position)
	{
		return std::make_shared<BonusObject_MultiMiniBall>(position);

	}
}
