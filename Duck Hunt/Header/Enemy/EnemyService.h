#pragma once
#include <vector>

namespace Enemy
{
	enum class EnemyType;
	class EnemyController;
	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemyList;

		EnemyController* CreateEnemy(EnemyType enemyType);
		EnemyType GetRandomEnemyType();
		void SpawnEnemy();

	public:
		EnemyService();
		~EnemyService();

		void Initialize();
		void Update();
		void Render();



	};
}

