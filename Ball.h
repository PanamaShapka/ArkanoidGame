#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class CollisionHandler;

	class BallState {
	public:
		virtual ~BallState() {};

		virtual int GetDamage() = 0;
		virtual float GetRadius() = 0;
		virtual sf::Color GetColor() = 0;
	};

	class BallStateDefault : public BallState {
	public:
		~BallStateDefault() {};

		virtual int GetDamage() override { return 1; }
		virtual float GetRadius() override { return 10.f; }
		virtual sf::Color GetColor() override { return sf::Color::Yellow; }
	};

	class BallStateFireball : public BallState {
	public:
		~BallStateFireball() {};

		virtual int GetDamage() override { return 2; }
		virtual float GetRadius() override { return 10.f; }
		virtual sf::Color GetColor() override { return sf::Color::Red; }
	};

	class BallStateMini : public BallState {
	public:
		~BallStateMini() {};

		virtual int GetDamage() override { return 1; }
		virtual float GetRadius() override { return 7.5f; }
		virtual sf::Color GetColor() override { return sf::Color(255, 165, 0, 255); }
	};

	class Ball : public GameObject
	{
	public:

		friend CollisionHandler;

		~Ball();
		Ball(sf::Vector2f position);
		Ball() : Ball(sf::Vector2f((float)SCREEN_WIDTH / 2.f, (float)SCREEN_HEIGHT - 175.f)) {}

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window) override;


		void SetState(std::shared_ptr<BallState> state);

		sf::Vector2f GetPosition() { return ball.getPosition(); }
		float GetRadius() { return ball.getRadius(); }
		int GetAmountDamage() { return state->GetDamage(); }

		void SetStartState();
		
	private:

		void SetRandomAxisSpeed();

		enum class BallMovementX {
			RIGHT_MOVEMENT,
			LEFT_MOVEMENT,
			NONE
		};

		enum class BallMovementY {
			UP_MOVEMENT,
			DOWN_MOVEMENT,
			NONE
		};

		void ChangeBallMovement(BallMovementX ballMovementX, BallMovementY ballMovementY);
		

	private:

		bool isCollideWithScreenBorders = false;
		bool isCollideWithPlatform = false;
		sf::Vector2f axisSpeed;
		sf::CircleShape ball;
		std::shared_ptr<BallState> state;
	};

}

