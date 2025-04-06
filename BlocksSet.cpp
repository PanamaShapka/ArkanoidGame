#include "BlocksSet.h"
#include "Application.h"

namespace ArkanoidGame {

	BlocksSet::BlocksSet()
	{
		
	}

	void BlocksSet::HitBlock(sf::Vector2i positionOnField, Ball& ball)
	{ 
		for (auto currentBlock = blocks.begin(); currentBlock != blocks.end(); ++currentBlock) {
			if (currentBlock->get()->GetPositionOnField() == positionOnField) {
				currentBlock->get()->Hit(ball);
				if (currentBlock->get()->CheckHP()) { // Destroy block
					Application::Instance().GetGame().GetBonusObjectSet().SpawnBonusWithChance(currentBlock->get()->GetPosition());
					Notify(*currentBlock);
					blocks.erase(currentBlock);
				}
				return;
			}
		}
	}

	void BlocksSet::DestroyBlock(sf::Vector2i positionOnField)
	{
		for (auto currentBlock = blocks.begin(); currentBlock != blocks.end(); ++currentBlock) {
			if (currentBlock->get()->GetPositionOnField() == positionOnField) {
				blocks.erase(currentBlock);
				return;
			}	
		}
	}

	void BlocksSet::Draw(sf::RenderWindow& window)
	{
		for (auto& currentBlock : blocks) {
			currentBlock->Draw(window);
		}
	}

	void BlocksSet::SetStartState()
	{
		pointsCounter = Application::Instance().GetGame().GetPointsCounter();
		blocks.clear();

		// Generate random non-repeating blocks indexes
		std::vector<int> blocksIndexes;
		blocksIndexes.insert(blocksIndexes.begin(), AMOUNT_OF_BLOCKS, 0);
		fillVectorWithRandomBlocksIndexes(blocksIndexes);
			
		// Set blocks to their indexes
		for (int blockIndex : blocksIndexes) {

			sf::Vector2i position;
			position.x = (blockIndex - 1) % 10;
			position.y = (blockIndex - 1) / 10;

			if (rand() % int(CHANCE_TO_GET_GLASS_BLOCK * 100) == 0) { // Spawn glass block
				blocks.emplace_back(std::make_shared<GlassBlock>(position));
			}
			else { // Spawn basic block
				blocks.emplace_back(std::make_shared<BasicBlock>(position));
			}
		}
	}

	void BlocksSet::ReplaceAllToGlassBlocks()
	{
		for (auto& currentBlock : blocks) {
			currentBlock = std::make_shared<GlassBlock>(currentBlock->GetPositionOnField());
		}
	}

	void BlocksSet::SetBlockSet(BlocksSet blockSet)
	{
		this->blocks = blockSet.blocks;
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

					// set i to iterate thought the vector from its beggining
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
