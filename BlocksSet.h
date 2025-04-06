#pragma once
#include "BasicBlock.h"
#include "GlassBlock.h"
#include "PointsCounter.h"

namespace ArkanoidGame {

	class CollisionHandler;
	class Ball;

	class BlocksSet : public GameObject, public PointsCounterObserverable
	{
	public:

		BlocksSet();
		~BlocksSet() {}

		friend CollisionHandler;

		void HitBlock(sf::Vector2i positionOnField, Ball& ball);
		void DestroyBlock(sf::Vector2i positionOnField);
		void Draw(sf::RenderWindow& window) override;
		void SetStartState();
		
		int GetAmountBlocks() { return blocks.size(); }
		void ReplaceAllToGlassBlocks();
		void SetBlockSet(BlocksSet blockSet);

		std::vector<std::shared_ptr<Block>> GetBlocks() { return blocks; }

	private:

		void fillVectorWithRandomBlocksIndexes(std::vector<int>& blocksIndexes);

	private:

		std::vector<std::shared_ptr<Block>> blocks;

	};

}

