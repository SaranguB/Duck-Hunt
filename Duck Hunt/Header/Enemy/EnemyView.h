#pragma once
#include "../../Header/UI/UIElement/ImageView.h"


namespace Enemy
{
	class EnemyModel;
	class EnemyController;
	class EnemyView
		
	{
	private:
		EnemyModel* enemyModel;
		EnemyController* enemyController;
		UI::UIElement::ImageView* enemyImage;

	public:
		EnemyView();
		~EnemyView();
		
		const float enemySpriteHeight = 150.f;
		const float enemySpriteWidth = 150.f;

		void InitializeEnemySprite();

		void Initialize();
		void Update();
		void Render();

	};
}