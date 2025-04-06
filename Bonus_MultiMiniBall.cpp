#include "Bonus_MultiMiniBall.h"
#include "Application.h"

namespace ArkanoidGame {

	void Bonus_MultiMiniBall::Activation()
	{
		Application::Instance().GetGame().GetMiniBallsSet().Activate();
	}

	void Bonus_MultiMiniBall::Deactivation()
	{
		Application::Instance().GetGame().GetMiniBallsSet().Deactivate();
	}

	void MiniBallsSet::Update(float deltaTime)
	{
		if (Application::Instance().GetGame().GetBonusSet().GetBonus(BonusSet::BonusType::MULTI_MINI_BALL)->IsActive()) {
			for (Ball& currentBall : miniBallsSet) {
				currentBall.Update(deltaTime);
			}
		}
	}

	void MiniBallsSet::Draw(sf::RenderWindow& window)
	{
		if (Application::Instance().GetGame().GetBonusSet().GetBonus(BonusSet::BonusType::MULTI_MINI_BALL)->IsActive()) {
			for (Ball& currentBall : miniBallsSet) {
				currentBall.Draw(window);
			}
		}
	}

	void MiniBallsSet::Activate()
	{
		for (int i = 0; i < 10; ++i) {
			miniBallsSet.emplace_back(Ball(Application::Instance().GetGame().GetBall().GetPosition()));
			miniBallsSet.at(miniBallsSet.size() - 1).SetState(std::make_shared<BallStateMini>());
		}
	}

	void ArkanoidGame::MiniBallsSet::Deactivate()
	{
		miniBallsSet.clear();
	}

	void MiniBallsSet::DeleteBall(std::vector<Ball>::iterator ballIterator)
	{
		miniBallsSet.erase(ballIterator);

		if (miniBallsSet.empty()) {
			Application::Instance().GetGame().GetBonusSet().GetBonus(BonusSet::BonusType::MULTI_MINI_BALL)->Deactivate();
		}
	}

}