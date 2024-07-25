#include "../../Header/Global/ServiceLocator.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Gameplay;
	using namespace Enemy;

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
		gameplayService = new GameplayService();
		enemyService = new EnemyService();

	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		delete(eventService);
		delete(gameplayService);
		delete(enemyService);

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
		gameplayService->Initialize();
		enemyService->Initialize();
	}
	void ServiceLocator::Update()
	{
		eventService->Update();
		gameplayService->Update();
		enemyService->Update();


	}
	void ServiceLocator::Render()
	{
		gameplayService->Render();
		enemyService->Render();
	}
	Graphics::GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicService;
	}
	Event::EventService* ServiceLocator::GetEventService()
	{
		return eventService;
	}

	Gameplay::GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}
	Enemy::EnemyService* ServiceLocator::GetEnemyService()
	{
		return enemyService;
	}
}