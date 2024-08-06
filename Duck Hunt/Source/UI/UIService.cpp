#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"



namespace UI
{
	using namespace Main;
	using namespace Interface;
	using namespace UIElement;
	using namespace GameplayUI;
	using namespace WaveUI;
	using namespace EndscreenUI;

	UIService::UIService()
	{
		CreateController();
	}

	UIService::~UIService()
	{
		delete(gameplayUIController);
		delete(waveUIController);
		delete(endscreenUIController);
	}

	void UIService::CreateController()
	{
		gameplayUIController = new GameplayUIController();
		waveUIController = new WaveUIController();
		endscreenUIController = new EndscreenUIController();
	}

	void UIService::Initialize()
	{
		InitializeController();
	}

	void UIService::InitializeController()
	{
		gameplayUIController->Initialize();
		waveUIController->Initialize();
		endscreenUIController->Initialize();
	}

	void UIService::update()
	{
		IUIController* uiController = getCurrentUIController();

		if (uiController) uiController->Update();
	}

	void UIService::Render()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->Render();
	}



	Interface::IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::GetGameState())
		{

		case GameState::GAMEPLAY:
			return gameplayUIController;

		case GameState::WAVE:
			return waveUIController;

		case GameState::CREDITS:
			return endscreenUIController;
				
		default:
			return nullptr;
		}
	}

}