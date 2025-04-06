#include "PointsCounter.h"
#include "Application.h"

namespace ArkanoidGame {

	void PointsCounter::AddPoints(std::shared_ptr<Block> destroyedBlock)
	{
		points += (destroyedBlock->GetMaxHP() * 100);
	} 

	void PointsCounter::SetStartState()
	{
		points = 0;
	}

	void PointsCounter::UpdateBestPoints()
	{
		if (bestPoints < points) {
			bestPoints = points;
		}
	}

	void PointsCounterObserverable::Notify(std::shared_ptr<Block> destroyedBlock)
	{
		pointsCounter->AddPoints(destroyedBlock);
	}
}
