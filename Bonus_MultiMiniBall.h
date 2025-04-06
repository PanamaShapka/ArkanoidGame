#pragma once
#include "Bonus.h"
#include "Ball.h"

namespace ArkanoidGame {

	class Bonus_MultiMiniBall : public ActivatingBonus
	{
	public:

		Bonus_MultiMiniBall() = default;
		~Bonus_MultiMiniBall() = default;

	private:

		void Activation() override;
		void Deactivation() override;

	private:

	};

	class MiniBallsSet : public GameObject {
	public:

		friend Bonus_MultiMiniBall;
		friend CollisionHandler;

		void Draw(sf::RenderWindow& window) override;
		void Update(float deltaTime);

	private:

		void Activate();
		void Deactivate();
		void DeleteBall(std::vector<Ball>::iterator ballIterator);

	private:
		std::vector<Ball> miniBallsSet;
	};
}

