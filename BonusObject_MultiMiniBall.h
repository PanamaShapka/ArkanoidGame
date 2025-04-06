#pragma once
#include "BonusObject.h"

namespace ArkanoidGame {

	class BonusObject_MultiMiniBall : public BonusObject
	{
	public:

		BonusObject_MultiMiniBall(const sf::Vector2f& position) : BonusObject(position) { SetBonusColor(); }

	private:

		void Activation() override;
		void SetBonusColor() override;
	};

}

