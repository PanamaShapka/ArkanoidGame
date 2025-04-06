#pragma once
#include "BonusObject.h"

namespace ArkanoidGame {

	class BonusObject_GlassBlocks : public BonusObject
	{
	public:
		BonusObject_GlassBlocks(const sf::Vector2f& position) : BonusObject(position) { SetBonusColor(); }

	private:

		void Activation() override;
		void SetBonusColor() override;
	};

}

