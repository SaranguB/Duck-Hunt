#pragma once
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}

	GameplayService::~GameplayService()
	{

	}

	void GameplayService::Initialize()
	{
		gameplayController->Initialize();
	}
	void GameplayService::Update()
	{
		gameplayController->Update();
	}
	void GameplayService::Render()
	{
		gameplayController->Render();
	}
}
