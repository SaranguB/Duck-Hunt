#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Player/PlayerModel.h"

namespace Gameplay
{
	using namespace UI::UIElement;
	using namespace Global;
	using namespace Player;
	using namespace Enemy;

	GameplayView::GameplayView()
	{
		gameplayImage = new ImageView();
		
	}

	GameplayView::~GameplayView()
	{
		delete(gameplayImage);
		
	}

	void GameplayView::Initialize()
	{

		InitializeBackgroundImage();
	}

	void GameplayView::Update()
	{
		gameplayImage->Update();
		
	}
	void GameplayView::Render()
	{
		gameplayImage->Render();
		
	}

	void GameplayView::InitializeBackgroundImage()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
		gameplayImage->Initialize(Config::Duck_Hunt_BG_Texture_Path,
			gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));
	}

	

}