#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Event
{
	using namespace Global;

	EventService::EventService()
	{
		gameWindow = nullptr;
	}
	EventService::~EventService()
	{
		//delete(gameWindow);
	}

	void EventService::Initialize()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
	}

	void EventService::Update()
	{

	}

	void EventService::ProcessEvent()
	{
		if (ISGameWindowOpen())
		{
			while (gameWindow->pollEvent(gameEvent))
			{
				if (GameWindowWasClosed() || HasQuitGame())
				{
					gameWindow->close();
				}
			}
		}
	}

	bool EventService::HasQuitGame()
	{
		return (ISKeyBoardEvent() && PressedEscapeKey());
	}

	bool EventService::ISKeyBoardEvent()
	{
		return gameEvent.type == sf::Event::KeyPressed;
	}

	bool EventService::PressedEscapeKey()
	{
		return gameEvent.key.code == sf::Keyboard::Escape;

	}

	bool EventService::ISGameWindowOpen()
	{
		return gameWindow != nullptr;
	}

	bool EventService::GameWindowWasClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}
	
	
}