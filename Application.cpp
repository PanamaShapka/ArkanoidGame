#include "Application.h"
#include <cstdlib>

namespace ArkanoidGame {

	Application& Application::Instance() 
	{
		static Application instance;
		return instance;
	}

	Application::Application() : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME) 
	{	
		//srand(time(NULL)); Не работает оно тут :(
	}

	Application::~Application() 
	{
		// Shutdown game
	}

	void Application::Run() 
	{
		// Init game clock
		sf::Clock gameClock;
		float lastTime = gameClock.getElapsedTime().asSeconds();

		// Game loop
		while (window.isOpen()) {

			// Calculate time delta
			float currentTime = gameClock.getElapsedTime().asSeconds();
			float deltaTime = currentTime - lastTime;
			lastTime = currentTime;

			// Read events
			sf::Event event;
			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed) {
					window.close();
					break;
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
					window.close();
					break;
				}
			}

			// Update game
			game.Update(deltaTime);

			// Draw game
			game.Draw(window);
			window.display();
		}
	}
}
