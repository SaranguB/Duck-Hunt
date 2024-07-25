#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Event/EventService.h"

namespace Global
{
	class ServiceLocator
	{
	private:

		Graphics::GraphicService* graphicService;
		Event::EventService* eventService;

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
	};
}
