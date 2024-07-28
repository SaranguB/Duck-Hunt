#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class EnemyType;
	class EnemyController;
	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemyList;
		std::vector<EnemyController*> flaggedEnemyList;

		const float spawnInterval = 2.f;
		float spawnTimer = spawnInterval;

		EnemyController* CreateEnemy(EnemyType enemyType);
		EnemyType GetRandomEnemyType();
		
		void UpdateSpawnTimer();
		void SpawnEnemy();
		void ProcessSpawnEnemy();
		void DestroyEnemy(EnemyController* controller);

	public:
		EnemyService();
		~EnemyService();

		void Initialize();
		void Update();
		void Render();

		bool DestroyEnemyAtMousePosition(sf::Vector2f mousePosition);
		void DestroyFlaggedEnemyList();



	};
}

