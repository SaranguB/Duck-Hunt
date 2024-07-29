#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;
	using namespace Wave;

	PlayerController::PlayerController()
	{
		playerModel = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
	}
	void PlayerController::Initialize()
	{
		playerModel->Initialize();
	}

	void PlayerController::Update()
	{
		if(PlayerModel::playerAmmo >0)
			ProcessPlayerInput();
		
			
		
	}

	void PlayerController::ProcessPlayerInput()
	{
		Event::EventService* eventService = ServiceLocator::GetInstance()->GetEventService();
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();

		if (eventService->PressedLeftMouseButton())
		{
			/*printf("Mouse click detected.\n");*/

			DecreasePlayerAmmo();
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));
			
			//printf("Mouse Position: %f, %f\n", mousePosition.x, mousePosition.y);

			bool destroyed = false;
			destroyed = ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemyAtMousePosition(mousePosition);
		    
			/*if (destroyed)
			{
				printf("Enemy destroyed at position: %f, %f\n", mousePosition.x, mousePosition.y);
			}
			else
			{
				printf("No enemy found at position: %f, %f\n", mousePosition.x, mousePosition.y);
			}*/
		}
	}

	void PlayerController::DecreasePlayerAmmo()
	{
		PlayerModel::playerAmmo --;
	}

	void PlayerController::Reset()
	{
		PlayerModel::playerAmmo = 10;
	}



	


	
}