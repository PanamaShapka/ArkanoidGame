#pragma once
#include "BonusObject.h"

namespace ArkanoidGame {

	class BonusObject_Fireball : public BonusObject
	{
	public:

 		BonusObject_Fireball(const sf::Vector2f& position) : BonusObject(position) { SetBonusColor(); }

	private:

		void Activation() override;
		void SetBonusColor() override;
	};

}
