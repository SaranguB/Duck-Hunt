#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace Gameplay
{
	using namespace UI::UIElement;
	using namespace Global;

	GameplayView::GameplayView()
	{
		gameplayImage = new ImageView();
		
	}

	GameplayView::~GameplayView()
	{
	}

	void GameplayView::Initialize()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
		gameplayImage->Initialize(Config::Duck_Hunt_BG_Texture_Path,
			gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0,0));

	}

	void GameplayView::Update()
	{
		gameplayImage->Update();
	}
	void GameplayView::Render()
	{
		gameplayImage->Render();
	}
}