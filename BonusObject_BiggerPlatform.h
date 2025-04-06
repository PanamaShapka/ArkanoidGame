#pragma once
#include "BonusObject.h"

namespace ArkanoidGame {

	class BonusObject_BiggerPlatform : public BonusObject
	{
	public:
		BonusObject_BiggerPlatform(const sf::Vector2f& position) : BonusObject(position) { SetBonusColor(); }

	private:

		void Activation() override;
		void SetBonusColor() override;
	};

}

