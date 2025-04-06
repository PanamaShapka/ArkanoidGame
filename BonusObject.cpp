#include "BonusObject.h"
#include "Application.h"

namespace ArkanoidGame {

	BonusObject::BonusObject(const sf::Vector2f& position)
	{
		bonusShape.setRadius(5.f);
		SetCircleRelativeOrigin(bonusShape, sf::Vector2f(0.5f, 0.5f));
		bonusShape.setPosition(position);
	}

	void BonusObject::Update(float deltaTime)
	{
		bonusShape.setPosition(sf::Vector2f(bonusShape.getPosition().x, bonusShape.getPosition().y + BONUS_SPEED * deltaTime));
	}

	void BonusObject::Draw(sf::RenderWindow& window)
	{
		window.draw(bonusShape);
	}

	void BonusObject::Activate()
	{
		Activation();
		SetShouldDeleteTrue();
	}
}

