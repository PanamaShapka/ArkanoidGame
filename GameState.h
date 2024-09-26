#pragma once
#include "Ball.h"

namespace ArkanoidGame {

	class GameState
	{
	public:

		enum class State {
			PLAYING = 0,
			MAIN_MENU,
			GAME_OVER
		};

		void SetState(State gameState);
		State GetState() { return gameState; };
		bool CheckState(State checkWithGameState);

	private:

		State gameState;
	};

}

