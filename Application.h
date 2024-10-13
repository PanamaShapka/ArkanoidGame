#pragma once
#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "Game.h"

namespace ArkanoidGame {

	class Application
	{
	public:
		Application(const Application& application) = delete;
		Application& operator=(const Application&) = delete;

		static Application& Instance();
	
		void Run();

		Game& GetGame() { return game; }
		GameState& GetGameState() { return gameState; }

	private:
		Application();
		~Application();

	private:
		GameState gameState;
		Game game;
		sf::RenderWindow window;
	};

}