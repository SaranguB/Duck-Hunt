#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controller/GreenDuckController.h"
#include "../../Header/Enemy/Controller/RedDuckController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
	using namespace Global;
	using namespace Controller;
	using namespace Wave;

	EnemyService::EnemyService()
	{
		wave = new WaveService();
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i] = nullptr;
		}
	}

	EnemyService::~EnemyService()
	{

		Destroy();
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
		EnemyModel::enemyCount++;

	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType)
	{

		switch (enemyType)
		{

		case EnemyType::GREEN_DUCK:
			return new GreenDuckController(EnemyType::GREEN_DUCK);
		case EnemyType::RED_DUCK:
			return new GreenDuckController(EnemyType::RED_DUCK);
		}

	}

	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 2;
		return static_cast<Enemy::EnemyType>(randomType);
	}

	void EnemyService::Update()
	{

		UpdateSpawnTimer();
		ProcessSpawnEnemy();

		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Update();

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
			if (ServiceLocator::GetInstance()->GetWaveService()->checkTimeForChange())
			{
				if (EnemyModel::enemiesKilled < ServiceLocator::GetInstance()->GetWaveService()->GetEnemiesToBeKilled())
				{
					ServiceLocator::GetInstance()->GetWaveService()->RestartClock();
					Reset();
					ServiceLocator::GetInstance()->GetPlayerService()->Reset();
					spawnTimer = 0;
				}
				else
				{
					WaveType currentWave = ServiceLocator::GetInstance()->GetWaveService()->GetCurrentWave();
					ServiceLocator::GetInstance()->GetWaveService()->ChangeWave(currentWave);
				}

			}

			if (EnemyModel::enemyCount < EnemyModel::NumberOfEnemies)
			{
				SpawnEnemy();
				spawnTimer = 0;
			}
		}
	}

	void EnemyService::Render()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Render();
		}
	}


	bool EnemyService::DestroyEnemyAtMousePosition(sf::Vector2f mousePosition)
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			sf::FloatRect bounds = enemyList[i]->GetEnemySprite().getGlobalBounds();
			//printf("Checking enemy %d with bounds: left=%f, top=%f, width=%f, height=%f\n", i, bounds.left, bounds.top, bounds.width, bounds.height);


			if (bounds.contains(mousePosition))
			{

				Enemy::EnemyModel::enemiesKilled++;
				//printf("Mouse position %f, %f is within the bounds of enemy %d\n", mousePosition.x, mousePosition.y, i);
				DestroyEnemy(enemyList[i]);
				return true;
				break;

			}

		}
	}

	void EnemyService::DestroyEnemy(EnemyController* controller)
	{
		flaggedEnemyList.push_back(controller);
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), controller), enemyList.end());
	}


	void EnemyService::Reset()
	{
		Destroy();
		Enemy::EnemyModel::enemyCount = 0;
		Enemy::EnemyModel::enemiesKilled = 0;
	}

	void EnemyService::Destroy()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			delete(enemyList[i]);
		}
		enemyList.clear();
	}

	void EnemyService::DestroyFlaggedEnemyList()
	{
		for (int i = 0;i < flaggedEnemyList.size();i++)
		{
			delete(flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}


}
