#include "Bonus_GlassBlocks.h"
#include "Application.h"

namespace ArkanoidGame {

	void Bonus_GlassBlocks::Activation()
	{
		blocksSetMemento.SetBlocksSet(Application::Instance().GetGame().GetBlocksSet());
		Application::Instance().GetGame().GetBlocksSet().ReplaceAllToGlassBlocks();
	}

	void Bonus_GlassBlocks::Deactivation()
	{	
		bool shouldDeleteBlockFromMemento = true;
		for (auto& currentBlockFromMemento : blocksSetMemento.GetBlocksSet().GetBlocks()) {
			for (auto& currentBlock : Application::Instance().GetGame().GetBlocksSet().GetBlocks()) {
				if (currentBlockFromMemento->GetPositionOnField() == currentBlock->GetPositionOnField()) {
					shouldDeleteBlockFromMemento = false;
					break;
				}
			}

			if (shouldDeleteBlockFromMemento) {
				blocksSetMemento.GetBlocksSet().DestroyBlock(currentBlockFromMemento->GetPositionOnField());
			}
			shouldDeleteBlockFromMemento = true;
		}
		

		Application::Instance().GetGame().GetBlocksSet().SetBlockSet(blocksSetMemento.GetBlocksSet());
	}

}
