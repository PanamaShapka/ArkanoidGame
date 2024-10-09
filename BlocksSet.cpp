#include "BlocksSet.h"

namespace ArkanoidGame {

	BlocksSet::BlocksSet()
	{
		SetStartState();
	}

	void BlocksSet::DestroyBlock(int blockIndex)
	{
		if (blockIndex < 0 || blockIndex >= blocksSet.size()) {
			return;
		}

		blocksSet.erase(blocksSet.begin() + blockIndex);
	}

	void BlocksSet::Draw(sf::RenderWindow& window)
	{
		for (auto& currentBlock : blocksSet) {
			currentBlock.Draw(window);
		}
	}

	void BlocksSet::SetStartState()
	{
		blocksSet.clear();
		blocksSet.reserve(50);

		// Generate random non-repeating blocks indexes
		std::vector<int> blocksIndexes;
		blocksIndexes.insert(blocksIndexes.begin(), blocksSet.capacity(), 0);
		fillVectorWithRandomBlocksIndexes(blocksIndexes);
			
		// Set blocks to their indexes
		for (int blockIndex : blocksIndexes) {

			sf::Vector2f position;
			position.x = (10.f + BLOCK_SIZE.x / 2) + (10.f + BLOCK_SIZE.x) * ((blockIndex - 1) % 10);
			position.y = (10.f + BLOCK_SIZE.y / 2) + (10.f + BLOCK_SIZE.y) * ((blockIndex - 1) / 10);

			blocksSet.push_back(Block(position));
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
