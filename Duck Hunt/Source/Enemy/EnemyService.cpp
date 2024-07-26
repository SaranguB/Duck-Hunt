#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/GreenDuckController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Controller;

	EnemyService::EnemyService()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i] = nullptr;
		}
	}

	EnemyService::~EnemyService()
	{

		for (int i = 0;i < enemyList.size();i++)
		{
			delete(enemyList[i]);
		}
	}

	void EnemyService::Initialize()
	{
		SpawnEnemy();
	}

	void EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());
		enemyController->Initialize();

		enemyList.push_back(enemyController);
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType)
	{
		
		switch (enemyType)
		{
			
		case EnemyType::GREEN_DUCK:
			return new GreenDuckController(EnemyType::GREEN_DUCK);
		}
		
	}

	EnemyType EnemyService::GetRandomEnemyType()
	{
		return EnemyType::GREEN_DUCK;

		/*int randomType = std::rand() % 1;
		return static_cast<Enemy::EnemyType>(randomType);*/
	}

	void EnemyService::Update()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Update();
		}
		
	}

	void EnemyService::Render()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Render();
		}
	}
}
