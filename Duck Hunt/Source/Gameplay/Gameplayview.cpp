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
		playerAmmo = new TextView();
		
	}

	GameplayView::~GameplayView()
	{
		delete(gameplayImage);
		delete(enemiesKilledText);
		delete(playerAmmo);

	}

	void GameplayView::Initialize()
	{

		InitializeBackgroundImage();
		InitializeEnemiesKilledText();
		InitializePlayerAmmo();

		
	
	}

	void GameplayView::Update()
	{
		
		UpdateEnemiesKilledText();
		UpdatePlayerAmmoText();
		
	}
	void GameplayView::Render()
	{
		gameplayImage->Render();
		enemiesKilledText->Render();
		playerAmmo->Render();
	}

	void GameplayView::UpdateEnemiesKilledText()
	{
		sf::String enemiesKilledString = "Enemies Killed :" + std::to_string(PlayerModel::enemiesKilled);
		enemiesKilledText->setText(enemiesKilledString);
	}

	void GameplayView::UpdatePlayerAmmoText()
	{
		sf::String enemiesKilledString = "Player Ammo :" + std::to_string(PlayerModel::playerAmmo);
		playerAmmo->setText(enemiesKilledString);
	}

	void GameplayView::InitializeBackgroundImage()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
		gameplayImage->Initialize(Config::Duck_Hunt_BG_Texture_Path,
			gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));
	}

	void GameplayView::InitializeEnemiesKilledText()
	{
		enemiesKilledText->Initialize("Enemies Killed : 0", sf::Vector2f(enemiesKilledTextXPosition, textYPosition),
			FontType::BUBBLE_BOBBLE, fontSize, textColor);
	}

	void GameplayView::InitializePlayerAmmo()
	{
		playerAmmo->Initialize("Player Ammo : 0", sf::Vector2f(playerAmmoTextXPosition, textYPosition),
			FontType::BUBBLE_BOBBLE, fontSize, textColor);
	}

}