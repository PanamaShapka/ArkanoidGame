#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class BonusObject : public GameObject
	{
	public:

		virtual ~BonusObject() = default;
		BonusObject(const sf::Vector2f& position);

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window) override;
		void Activate();

		void SetShouldDeleteTrue() { shouldDelete = true; }

		sf::Vector2f GetPosition() { return bonusShape.getPosition(); }
		float GetRadius() { return bonusShape.getRadius(); }
		bool ShouldDelete() { return shouldDelete; }

	protected:

		virtual void SetBonusColor() = 0;
		virtual void Activation() = 0;

	protected:

		sf::CircleShape bonusShape;
		bool shouldDelete = false;
	};

}

