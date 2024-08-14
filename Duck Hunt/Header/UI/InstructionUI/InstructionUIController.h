#pragma once
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	namespace InstructionUI
	{
		class InstructionUIController : public Interface::IUIController
		{
		private:
			UIElement::TextView* instructionText;
			UIElement::ButtonView* menuButton;
			UIElement::ImageView* backgroundImage;
			sf::RenderWindow* gameWindow;

			const float buttonWidth = 140.f;
			const float buttonHeight = 80.f;

			const float playButtonXposition = 900.f;
			const float playButtonYposition = 940.f;

			const float fontSize = 30.f;

			const sf::String text = R"(
                                                                      

    Objective: Shoot a set number of ducks within a time limit to advance through waves.

    Controls: Use the mouse to aim and left-click to shoot. Watch your ammo. running out ends the wave.

    Waves: Complete each wave by shooting the required number of ducks before time runs out or ammo is
 depleted. Failing costs a life, and the wave repeats.

    Ducks: There are two types of ducks, each with different point values. Ducks change direction every 
few seconds, making them harder to hit.

    Lives: Start with 3 lives. Losing all lives ends the game.

    Winning: Finish all waves with at least one life remaining to win. The background color changes based 
on your success.

    Tips: Lead your shots and conserve ammo. every shot counts!
)";

			const sf::Color textColor = sf::Color::White;

		public:
			InstructionUIController();
			~InstructionUIController();

			float waveXposition;
			float waveYPosition;

			void Initialize() override;
			void Update() override;
			void Render() override;


			void InitialzeInstructionText();
			void InitializeButton();
			void MenuButtonCallback();

			sf::Vector2f GetTextcentreAligned();
			void RegisterButtonCallback();

			void Show();

		};
	}
}
