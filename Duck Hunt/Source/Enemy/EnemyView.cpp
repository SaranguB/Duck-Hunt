#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyController.h"
namespace Enemy
{
	using namespace UI::UIElement;
	using namespace Global;

	EnemyView::EnemyView()
	{
		enemyImage = new ImageView();
		
	}

	EnemyView::~EnemyView()
	{
	}

	void EnemyView::Initialize()
	{
		enemyController = new EnemyController();
		InitializeEnemySprite();
	}

	void EnemyView::InitializeEnemySprite()
	{
		enemyImage->Initialize(Config::Green_Duck_Enemy, 
			enemySpriteWidth, enemySpriteHeight, enemyController->GetEnemyPosition() );

	}

	void EnemyView::Update()
	{
		enemyImage->Update();
	}

	void EnemyView::Render()
	{
		enemyImage->Render();
	}
}