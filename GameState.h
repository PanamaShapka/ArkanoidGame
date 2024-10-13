#pragma once
#include "GameState_Playing.h"
#include "GameState_GameOverMenu.h"
#include "GameState_MainMenu.h"
#include "GameState_GameWinMenu.h"

namespace ArkanoidGame {

	class GameState
	{
	public:

		enum class State {
			PLAYING = 0,
			MAIN_MENU,
			GAME_OVER,
			GAME_WIN
		};

		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);
		void SetStartState();
		void SetState(State state);

	private:

		GameState_Playing gameState_Playing;
		GameState_GameOverMenu gameState_GameOverMenu;
		GameState_MainMenu gameState_MainMenu;
		GameState_GameWinMenu gameState_GameWinMenu;

		State state = State::MAIN_MENU;
		GameStateData* gameStateData = &gameState_MainMenu;

	};

}

