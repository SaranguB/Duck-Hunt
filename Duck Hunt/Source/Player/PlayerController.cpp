#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;
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
		ProcessPlayerInput();
	}

	void PlayerController::ProcessPlayerInput()
	{
		Event::EventService* eventService = ServiceLocator::GetInstance()->GetEventService();
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
		
		if (eventService->PressedLeftMouseButton())
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));
		
		}
	}

	sf::Vector2f PlayerController::GetMouseButtonPosition()
	{
		return sf::Vector2f();
	}

	
	
}