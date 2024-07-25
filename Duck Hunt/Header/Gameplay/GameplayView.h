#pragma once
#include "../../Header/UI/UIElement/ImageView.h"

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



	};
}