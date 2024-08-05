#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"



namespace UI
{
	using namespace Main;
	using namespace Interface;
	using namespace UIElement;
	using namespace GameplayUI;

	UIService::UIService()
	{
		CreateController();
	}

	UIService::~UIService()
	{
		delete(gameplayUIController);
	}

	void UIService::CreateController()
	{
		gameplayUIController = new GameplayUIController();
	}

	void UIService::Initialize()
	{
		InitializeController();
	}

	void UIService::InitializeController()
	{
		gameplayUIController->Initialize();
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

		default:
			return nullptr;
		}
	}

}