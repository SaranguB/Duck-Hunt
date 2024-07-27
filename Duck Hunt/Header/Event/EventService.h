#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event
{
	class EventService
	{
	private:

		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;

		bool ISGameWindowOpen();
		bool GameWindowWasClosed();
		bool HasQuitGame();

		bool ISKeyBoardEvent();
		bool PressedEscapeKey();
		
		

	public:
		EventService();
		~EventService();

		void ProcessEvent();

		void Initialize();
		void Update();

		bool PressedLeftMouseButton();
		


	};
}