#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	namespace WaveUI
	{
		class WaveUIController : public Interface::IUIController
		{
		private:
			UIElement::TextView* waveText;
			sf::RenderWindow* gameWindow;

			const float fontSize = 100.f;

			const sf::Color textColor = sf::Color::White;

		public:
			WaveUIController();
			~WaveUIController();

			float waveXposition;
			float waveYPosition;

			void Initialize() override;
			void Update() override;
			void Render() override;


			void InitialzeWaveText();
			void DisplayWaveText();
			sf::String CurrentWaveText();

			sf::Vector2f GetTextcentreAligned();

		};
	}
}
