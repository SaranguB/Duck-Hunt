#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Gameplay/GameplayService.h"

namespace Global
{
	class ServiceLocator
	{
	private:

		Graphics::GraphicService* graphicService;
		Event::EventService* eventService;
		Gameplay::GameplayService* gameplayService;

		ServiceLocator();
		~ServiceLocator();

		void CreateServices();
		void ClearAllServices();


	public:

		static ServiceLocator* GetInstance();

		void Initialize();
		void Update();
		void Render();

		Graphics::GraphicService* GetGraphicService();
		Event::EventService* GetEventService();
		Gameplay::GameplayService* GetGameplayService();
	};
}
