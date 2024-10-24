#include "BlocksSet.h"

namespace ArkanoidGame {

	BlocksSet::BlocksSet()
	{
		
	}

	BlocksSet::~BlocksSet()
	{

	}

	void BlocksSet::HitBlock(sf::Vector2i positionOnField)
	{ 
		int index = -1;
		for (BasicBlock& currentBlock : basicBlocks) {
			++index;
			if (currentBlock.GetPositionOnField() == positionOnField) {
				currentBlock.Hit();
				if (currentBlock.CheckHP()) {
					basicBlocks.erase(basicBlocks.begin() + index);
				}
			}
		}

		index = -1;
		for (GlassBlock& currentBlock : glassBlocks) {
			++index;
			if (currentBlock.GetPositionOnField() == positionOnField) {
				currentBlock.Hit();
				if (currentBlock.CheckHP()) {
					glassBlocks.erase(glassBlocks.begin() + index);
				}
			}
		}

	}

	void BlocksSet::Draw(sf::RenderWindow& window)
	{
		for (BasicBlock& currentBlock : basicBlocks) {
			currentBlock.Draw(window);
		}
		for (GlassBlock& currentBlock : glassBlocks) {
			currentBlock.Draw(window);
		}
	}

	void BlocksSet::SetStartState()
	{
		basicBlocks.clear();
		glassBlocks.clear();

		// Generate random non-repeating blocks indexes
		std::vector<int> blocksIndexes;
		blocksIndexes.insert(blocksIndexes.begin(), AMOUNT_OF_BLOCKS, 0);
		fillVectorWithRandomBlocksIndexes(blocksIndexes);
			
		// Set blocks to their indexes
		for (int blockIndex : blocksIndexes) {

			sf::Vector2i position;
			position.x = (blockIndex - 1) % 10;
			position.y = (blockIndex - 1) / 10;

			if (rand() % int(CHANCE_TO_GET_GLASS_BLOCK * 100) == 0) {
				glassBlocks.push_back(GlassBlock(position));
			}
			else {
				basicBlocks.push_back(BasicBlock(position));
			}
		}
	}

	void BlocksSet::fillVectorWithRandomBlocksIndexes(std::vector<int>& blocksIndexes)
	{
		std::vector<int> usedIndexes;
		usedIndexes.reserve(blocksIndexes.size());

		// Set blocks indexes
		for (int& currentBlockIndex : blocksIndexes) {

			// Generate random index in [1; 100]
			int index = (rand() % 99 + 1);

			// Check indexes repetitions
			for (int i = 0; i < usedIndexes.size(); ++i) {
				if (index == blocksIndexes.at(i)) {

					// Generate new random index in [1; 100]
					if (index != 100) {
						index += 1;
					}
					else {
						index = 1;
					}

					// set |i| to iterate thought the vector from its beggining
					i = -1;
				}
			}

			// Set the new used index
			usedIndexes.push_back(index);

			// Set index
			currentBlockIndex = index;
		}
	}
}
