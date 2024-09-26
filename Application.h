#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Constants.h"
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

	private:
		Application();
		~Application();

	private:
		Game game;
		sf::RenderWindow window;
	};

}