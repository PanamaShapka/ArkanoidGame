#pragma once
#include "SFML/Graphics.hpp"
#include "BonusObject_BiggerPlatform.h"
#include "BonusObject_Fireball.h"
#include "BonusObject_GlassBlocks.h"
#include "BonusObject_MultiMiniBall.h"

namespace ArkanoidGame {

	class BonusObject;

	class BonusFactory
	{
	public:
		virtual std::shared_ptr<BonusObject> CreateBonusObject(const sf::Vector2f& position) = 0;
		virtual ~BonusFactory() = default;
	};

	class BiggerPlatformBonusObjectFactory final : public BonusFactory {
	public:
		virtual std::shared_ptr<BonusObject> CreateBonusObject(const sf::Vector2f& position);
		virtual ~BiggerPlatformBonusObjectFactory() = default;
	};

	class FireballBonusObjectFactory final : public BonusFactory {
	public:
		virtual std::shared_ptr<BonusObject> CreateBonusObject(const sf::Vector2f& position);
		virtual ~FireballBonusObjectFactory() = default;
	};

	class GlassBlocksBonusObjectFactory final : public BonusFactory {
	public:
		virtual std::shared_ptr<BonusObject> CreateBonusObject(const sf::Vector2f& position);
		virtual ~GlassBlocksBonusObjectFactory() = default;
	};

	class MutliMiniBallBonusObjectFactory final : public BonusFactory {
	public:
		virtual std::shared_ptr<BonusObject> CreateBonusObject(const sf::Vector2f& position);
		virtual ~MutliMiniBallBonusObjectFactory() = default;
	};

}

