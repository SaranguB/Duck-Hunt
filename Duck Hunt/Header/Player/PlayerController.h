#pragma once
#include "../../Header/Global/ServiceLocator.h"

namespace Player
{
	class PlayerModel;
	class Eventservice;
	class PlayerController
	{
	private:
		Eventservice* eventService;
		PlayerModel* playerModel;
		sf::RenderWindow* gameWindow;
		

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		
		sf::Vector2f GetMouseButtonPosition();
		void ProcessPlayerInput();

		void DecreasePlayerAmmo();

		



	};
}
