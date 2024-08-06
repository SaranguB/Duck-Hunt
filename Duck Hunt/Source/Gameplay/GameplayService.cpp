#pragma once
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Main;
	using namespace Global;
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
		
	}

	GameplayService::~GameplayService()
	{
		delete(gameplayController);
	}

	void GameplayService::Initialize()
	{
		gameplayController->Initialize();
	}
	void GameplayService::Update()
	{
		gameplayController->Update();

		if(GameService::GetGameState() == GameState::GAMEPLAY)
		ServiceLocator::GetInstance()->GetGraphicService()->ChangeWindowColor(sf::Color::Cyan);
	}
	void GameplayService::Render()
	{
		gameplayController->Render();
	}

}
