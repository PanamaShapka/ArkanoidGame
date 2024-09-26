#include "GameState.h"

namespace ArkanoidGame {

	void GameState::SetState(State gameState)
	{
		this->gameState = gameState;
	}

	bool GameState::CheckState(State checkWithGameState)
	{
		return gameState == checkWithGameState;
	}
}
