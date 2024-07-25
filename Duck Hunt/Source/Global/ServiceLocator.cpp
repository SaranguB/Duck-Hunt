#include "../../Header/Global/ServiceLocator.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;

	ServiceLocator::ServiceLocator()
	{
		CreateServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		ClearAllServices();
	}
	
	void ServiceLocator::CreateServices()
	{
		graphicService = new GraphicService();
		eventService = new EventService();
	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::Initialize()
	{
		graphicService->Initialize();
		eventService->Initialize();
	}
	void ServiceLocator::Update()
	{
		eventService->Update();

	}
	void ServiceLocator::Render()
	{

	}
	Graphics::GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicService;
	}
	Event::EventService* ServiceLocator::GetEventService()
	{
		return eventService;
	}
}