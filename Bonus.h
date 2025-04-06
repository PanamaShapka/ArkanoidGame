#pragma once
#include "Constants.h"

namespace ArkanoidGame {

	class Bonus
	{
	public:

		virtual ~Bonus() = default;
		Bonus() = default;

		virtual void Update(float deltaTime) = 0;
		virtual void Activate() = 0;
		virtual void Deactivate() = 0;
		bool IsActive() { return isActive; }

	protected:

		virtual void Activation() = 0;
		virtual void Deactivation() = 0;

	protected:

		bool isActive = false;
	};

	class TimeBonus : public Bonus {
	public:

		void Update(float deltaTime) override;
		void Activate() override;
		void Deactivate() override;

	protected:

	protected:

		float elapsedActiveTime = 0.f;
	};

	class ActivatingBonus : public Bonus {
	public:

		void Update(float deltaTime) override;
		void Activate() override;
		void Deactivate() override;

	protected:

	protected:

	};

}


