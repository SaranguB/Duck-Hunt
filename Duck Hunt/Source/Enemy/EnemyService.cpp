#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyService.h"

namespace Enemy
{
	EnemyService::EnemyService()
	{
		enemyController = new EnemyController();

	}

	EnemyService::~EnemyService()
	{
		delete(enemyController);
	}

	void EnemyService::Initialize()
	{
		enemyController->Initialize();
	}

	void EnemyService::Update()
	{
		enemyController->Update();
	}

	void EnemyService::Render()
	{
		enemyController->Render();
	}
}
