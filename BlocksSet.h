#pragma once
#include "Block.h"

namespace ArkanoidGame {

	class BlocksSet : GameObject
	{
	public:

		BlocksSet();
		~BlocksSet();

		void DestroyBlock(int blockIndex);
		void Draw(sf::RenderWindow& window) override;
		void SetStartState();
		
		std::vector<Block> GetBlocksSet() { return blocksSet; }

	private:

		void fillVectorWithRandomBlocksIndexes(std::vector<int>& blocksIndexes);

	private:

		std::vector<Block> blocksSet;

	};

}

