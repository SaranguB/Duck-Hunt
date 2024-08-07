#pragma once
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/TextView.h"


namespace Gameplay
{
	class GameplayView
	{
	private:

		UI::UIElement::ImageView* gameplayImage;
		sf::RenderWindow* gameWindow;

	public:
		GameplayView();
		~GameplayView();

		void Initialize();
		void Update();
		void Render();

		void InitializeBackgroundImage();

	};
}