#pragma once
#include "Bonus.h"
#include "BlocksSet.h"

namespace ArkanoidGame {

	class BlocksSetMemento {
	public:

		void SetBlocksSet(BlocksSet blocksSet) { this->blocksSet = blocksSet; }
		BlocksSet& GetBlocksSet() { return blocksSet; }

	private:
		BlocksSet blocksSet;
	};

	class Bonus_GlassBlocks : public TimeBonus
	{
	public:

		Bonus_GlassBlocks() = default;
		~Bonus_GlassBlocks() = default;

	private:

		void Activation() override;
		void Deactivation() override;

	private:
		BlocksSetMemento blocksSetMemento;
	};

}

