#pragma once
#include <memory>

namespace ArkanoidGame {

	class Block;

	class PointsCounter {
	public:

		void AddPoints(std::shared_ptr<Block> destroyedBlock);
		void SetStartState();
		int GetPoints() { return points; }
		int GetBestPoints() { return bestPoints; }
		void UpdateBestPoints();

	private:

	private:

		int points = 0;
		int bestPoints = 0;

	};

	class PointsCounterObserverable {
	public:
		
		PointsCounterObserverable() = default;
		virtual ~PointsCounterObserverable() = default;

	protected:

		void Notify(std::shared_ptr<Block> destroyedBlock);

	protected:

		std::shared_ptr<PointsCounter> pointsCounter = nullptr;
	};

}

