#include "GameState.h"
#include "Application.h"

namespace ArkanoidGame {

	void GameState::Update(float deltaTime)
	{
		gameStateData->Update(deltaTime, Application::Instance().GetGame());
	}

	void GameState::Draw(sf::RenderWindow& window)
	{
		gameStateData->Draw(window, Application::Instance().GetGame());
	}

	void GameState::SetStartState()
	{
		gameStateData->SetStartState(Application::Instance().GetGame());
	}

	void GameState::SetState(State state)
	{
		this->state = state;

		switch (this->state)
		{
		case State::PLAYING:
		{
			gameStateData = &gameState_Playing;
			break;
		}
		case State::MAIN_MENU:
		{
			gameStateData = &gameState_MainMenu;
			break;
		}
		case State::GAME_OVER:
		{
			gameStateData = &gameState_GameOverMenu;
			break;
		}
		case State::GAME_WIN:
		{
			gameStateData = &gameState_GameWinMenu;
			break;
		}
		default:
			break;
		}

		SetStartState();
	}
}
