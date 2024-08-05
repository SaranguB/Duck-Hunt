#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Player/PlayerModel.h"


namespace UI
{
	namespace GameplayUI

	{

		using namespace UIElement;
		using namespace Global;
		using namespace Player;
		using namespace Enemy;

		GameplayUIController::GameplayUIController()
		{
			
			enemiesKilledText = new TextView();
			playerAmmo = new TextView();
			playerScore = new TextView();
			playerLive = new TextView();
		}

		GameplayUIController::~GameplayUIController()
		{
			delete(enemiesKilledText);
			delete(playerAmmo);
			delete(playerScore);
			delete(playerLive);
		}

		void GameplayUIController::Initialize()
		{
			InitializeEnemiesKilledText();
			InitializePlayerAmmo();
			InitializePlayerScore();
			InitializePlayerLive();
		}

		void GameplayUIController::Update()
		{
			UpdateEnemiesKilledText();
			UpdatePlayerAmmoText();
			UpdatePlayerScore();
			UpdatePlayerLive();
		}

		void GameplayUIController::Render()
		{

			enemiesKilledText->Render();
			playerAmmo->Render();
			playerScore->Render();
			playerLive->Render();
		}

		void GameplayUIController::Show()
		{

		}


		void GameplayUIController::InitializeEnemiesKilledText()
		{
			enemiesKilledText->Initialize("Enemies Killed : 0", sf::Vector2f(enemiesKilledTextXPosition, textYPosition),
				FontType::BUBBLE_BOBBLE, fontSize, textColor);
		}

		void GameplayUIController::InitializePlayerAmmo()
		{
			playerAmmo->Initialize("Player Ammo : 0", sf::Vector2f(playerAmmoTextXPosition, textYPosition),
				FontType::BUBBLE_BOBBLE, fontSize, textColor);
		}

		void GameplayUIController::InitializePlayerLive()
		{
			playerLive->Initialize("Player Health : 0", sf::Vector2f(playerLiveTextXposition, 1000.f),
				FontType::BUBBLE_BOBBLE, fontSize, textColor);
		}

		void GameplayUIController::InitializePlayerScore()
		{
			playerScore->Initialize("Player Score : 0", sf::Vector2f(textXPosition, playerScoreTextYPosition),
				FontType::BUBBLE_BOBBLE, fontSize, textColor);
		}

		void GameplayUIController::UpdateEnemiesKilledText()
		{
			sf::String enemiesKilledString = "Enemies Killed :" + std::to_string(EnemyModel::enemiesKilled);
			enemiesKilledText->setText(enemiesKilledString);
		}

		void GameplayUIController::UpdatePlayerAmmoText()
		{
			sf::String enemiesKilledString = "Player Ammo :" + std::to_string(PlayerModel::playerAmmo);
			playerAmmo->setText(enemiesKilledString);
		}

		void GameplayUIController::UpdatePlayerScore()
		{
			int score = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerScore();
			sf::String enemiesKilledString = "Player Score : " + std::to_string(score);
			playerScore->setText(enemiesKilledString);
		}

		void GameplayUIController::UpdatePlayerLive()
		{
			sf::String enemiesKilledString = "Player Health : " + std::to_string(PlayerModel::playerLives);
			playerLive->setText(enemiesKilledString);
		}

	}
}

