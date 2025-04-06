#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "GameObject.h"

namespace ArkanoidGame {

	class CollisionHandler;

	class PlatformState {
	public:
		virtual ~PlatformState() {};

		virtual float GetWidth() = 0;
	};

	class PlatformStateDefault : public PlatformState {
	public:
		~PlatformStateDefault() {};

		virtual float GetWidth() override { return 150.f; }
	};

	class PlatformStateBigger : public PlatformState {
	public:
		~PlatformStateBigger() {};

		virtual float GetWidth() override { return 300.f; }
	};

	class Platform : public GameObject
	{
	public:

		Platform();
		~Platform();

		enum class PlatformDirection {
			RIGHT = 0,
			LEFT,
			NONE
		};

		void SetState(std::shared_ptr<PlatformState> state);

		void Update(PlatformDirection platformDirection, float deltaTime);
		void Draw(sf::RenderWindow& window) override;

		void SetStartState();

		sf::Vector2f GetPosition() { return platform.getPosition(); };
		sf::Vector2f GetSize() { return platform.getSize(); };
		PlatformDirection GetDirection() { return direction; }
		
	private:
		sf::RectangleShape platform;
		PlatformDirection direction;
		std::shared_ptr<PlatformState> state;
	};

}

