#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			UI::UIElement::ImageView* gameplayImage;
			UI::UIElement::TextView* enemiesKilledText;
			UI::UIElement::TextView* playerAmmo;
			UI::UIElement::TextView* playerScore;
			UI::UIElement::TextView* playerLive;

			sf::RenderWindow* gameWindow;

			const float enemiesKilledTextYPosition = 15.f;
			const float enemiesKilledTextXPosition = 800.f;

			const float playerAmmoTextXPosition = 900.f;
			const float playerAmmoTextYPosition = 1000.f;

			const float playerScoreTextYPosition = 1000.f;
			const float playerScoreTextXPosition = 60.f;

			const float playerLiveTextXposition = 1700.f;
			const float playerLiveTextYposition = 1000.f;

			const float fontSize = 40.f;

			const sf::Color textColor = sf::Color::White;



		public:
			GameplayUIController();
			~GameplayUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;

			void InitializeEnemiesKilledText();
			void InitializePlayerAmmo();
			void InitializePlayerLive();
			void InitializePlayerScore();

			void UpdateEnemiesKilledText();
			void UpdatePlayerAmmoText();
			void UpdatePlayerScore();
			void UpdatePlayerLive();





		};
	}
}
