#pragma once
#include "BasicBlock.h"
#include "GlassBlock.h"

namespace ArkanoidGame {

	class BlocksSet : public GameObject
	{
	public:

		BlocksSet();
		~BlocksSet();

		void HitBlock(sf::Vector2i positionOnField);
		void Draw(sf::RenderWindow& window) override;
		void SetStartState();
		
		int GetAmountBlocks() { return basicBlocks.size() + glassBlocks.size(); }
		std::vector<BasicBlock> GetBasicBlocks() { return basicBlocks; }
		std::vector<GlassBlock> GetGlassBlocks() { return glassBlocks; }

	private:

		void fillVectorWithRandomBlocksIndexes(std::vector<int>& blocksIndexes);

	private:

		std::vector<BasicBlock> basicBlocks;
		std::vector<GlassBlock> glassBlocks;

	};

}

