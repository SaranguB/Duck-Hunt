#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Gameplay;
	using namespace Enemy;
	using namespace Time;
	using namespace Player;
	using namespace Wave;
	using namespace Sound;
	using namespace UI;
	using namespace Main;

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
		waveService = new WaveService();
		enemyService = new EnemyService();
		timeService = new TimeService();
		playerService = new PlayerService();
		soundService = new SoundService();
		uiService = new UIService();

	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		delete(eventService);
		delete(gameplayService);
		delete(enemyService);
		delete(timeService);
		delete(playerService);
		delete(waveService);
		delete(soundService);
		delete(uiService);

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
		timeService->Initialize();
		uiService->Initialize();
		gameplayService->Initialize();
		soundService->Initialize();
		waveService->Initialize();
		enemyService->Initialize();
		playerService->Initialize();
	}
	void ServiceLocator::Update()
	{
		eventService->Update();
		timeService->Update();
		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{

			enemyService->Update();
			gameplayService->Update();
			playerService->Update();
		}
		uiService->update();


	}
	void ServiceLocator::Render()
	{
		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			enemyService->Render();
			gameplayService->Render();
		}
		uiService->Render();



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
	Time::TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}
	Player::PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}
	Wave::WaveService* ServiceLocator::GetWaveService()
	{
		return waveService;
	}
	Sound::SoundService* ServiceLocator::GetSoundService()
	{
		return soundService;
	}
	UI::UIService* ServiceLocator::GetUIService()
	{
		return uiService;
	}
}