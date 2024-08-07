#include "../../Header/Main/GameService.h"
#include "../../Header/Global/Config.h"

namespace Main
{
	using namespace Global;
	GameState GameService::currentState = GameState::BOOT;

	GameService::GameService()
	{
		serviceLocator = nullptr;
	}

	GameService::~GameService() = default;
	

	void GameService::Ignite()
	{
		serviceLocator = ServiceLocator::GetInstance();
		Initialize();
	}

	void GameService::Initialize()
	{
		serviceLocator->Initialize();
		InitializeVariable();
		SetGameState(GameState::GAMEPLAY);
	}

	void GameService::InitializeVariable()
	{
		gameWindow = serviceLocator->GetGraphicService()->GetGameWIndow();
	}

	void GameService::Update()
	{
		serviceLocator->GetEventService()->ProcessEvent();
		serviceLocator->Update();
	}
	void GameService::Render()
	{
		gameWindow->clear(serviceLocator->GetGraphicService()->GetWindowColor());
		serviceLocator->Render();
		gameWindow->display();
	}
	bool GameService::IsRunning()
	{
		return serviceLocator->GetGraphicService()->IsGameWindowOpen();
	}

	void GameService::SetGameState(GameState newState)
	{
		currentState = newState;
	}
	GameState GameService::GetGameState()
	{
		return currentState;
	}
}