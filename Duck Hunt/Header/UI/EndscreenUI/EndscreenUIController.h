#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"


namespace UI
{
	namespace EndscreenUI
	{
		class EndscreenUIController : public Interface::IUIController
		{
		private:
			UI::UIElement::ImageView* finalImageWon;
			UI::UIElement::ImageView* finalImageLose;

			sf::RenderWindow* gameWindow;

		public:
			EndscreenUIController();
			~EndscreenUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;

			void InitializeImage();


		};
	}
}
