#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Player/PlayerModel.h"

namespace Gameplay
{
	using namespace UI::UIElement;
	using namespace Global;
	using namespace Player;

	GameplayView::GameplayView()
	{
		gameplayImage = new ImageView();
		enemiesKilledText = new TextView();
		
	}

	GameplayView::~GameplayView()
	{
	}

	void GameplayView::Initialize()
	{

		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
		gameplayImage->Initialize(Config::Duck_Hunt_BG_Texture_Path,
			gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0,0));

		enemiesKilledText->Initialize("Enemies Killed : 0", sf::Vector2f(enemiesKilledTextXPosition, textYPosition),
			FontType::BUBBLE_BOBBLE, fontSize, textColor);
	
	}

	void GameplayView::Update()
	{
		gameplayImage->Update();
		enemiesKilledText->Update();
		UpdateEnemiesKilledText();
	}
	void GameplayView::Render()
	{
		gameplayImage->Render();
		enemiesKilledText->Render();

	}

	void GameplayView::UpdateEnemiesKilledText()
	{
		sf::String enemiesKilledString = "Enemies Killed :" + std::to_string(PlayerModel::enemiesKilled);
		enemiesKilledText->setText(enemiesKilledString);
	}

}