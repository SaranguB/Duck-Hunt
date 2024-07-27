#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controller/GreenDuckController.h"

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
		enemyList.clear();
	}

	void EnemyService::Initialize()
	{
		spawnTimer = 0;
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
		
		UpdateSpawnTimer();
		ProcessSpawnEnemy();

		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Update();
			enemyList[i]->GetEnemySprite();
			
		}
		DestroyFlaggedEnemyList();
	}

	void EnemyService::UpdateSpawnTimer()
	{
		spawnTimer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyService::ProcessSpawnEnemy()
	{
		if (spawnTimer > spawnInterval)
		{
			SpawnEnemy();
			spawnTimer = 0;
		}
	}

	void EnemyService::Render()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Render();
		}
	}

	void EnemyService::DestroyEnemyAtMousePosition(sf::Vector2f mousePosition)
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			if (enemyList[i]->GetEnemySprite().getGlobalBounds().contains(mousePosition))
			{
				DestroyEnemy(enemyList[i]);
				break;
			}
		}
	}

	void EnemyService::DestroyFlaggedEnemyList()
	{
		for (int i = 0;i < flaggedEnemyList.size();i++)
		{
			delete(flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}

	void EnemyService::DestroyEnemy(EnemyController* controller)
	{
		flaggedEnemyList.push_back(controller);
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), controller), enemyList.end());
	}
}
