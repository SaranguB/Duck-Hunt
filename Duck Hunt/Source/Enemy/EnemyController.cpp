#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
	EnemyController::EnemyController()
	{
		enemyModel = new EnemyModel();
		enemyView = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemyView);
		delete(enemyModel);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyView->Initialize();
	}

	void EnemyController::Update()
	{
		enemyView->Update();
		enemyModel->Update();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}
}