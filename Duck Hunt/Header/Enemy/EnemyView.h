#pragma once
#include "../../Header/UI/UIElement/ImageView.h"

namespace Enemy
{
	class EnemyView
	{
	private:
		UI::UIElement::ImageView* enemyImage;

	public:
		EnemyView();
		~EnemyView();
		
		void Initialize();
		void Update();
		void Render();

	};
}