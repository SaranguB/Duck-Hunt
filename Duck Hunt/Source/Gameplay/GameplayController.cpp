#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Gameplay/GameplayView.h"

namespace Gameplay
{
	GameplayController::GameplayController()
	{
		gameplayView = new GameplayView();
	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::Initialize()
	{
		gameplayView->Initialize();
	}

	void GameplayController::Update()
	{
		gameplayView->Update();
	}
	void GameplayController::Render()
	{
		gameplayView->Render();
	}
}
