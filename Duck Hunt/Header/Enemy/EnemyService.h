#pragma once

namespace Enemy
{
	class EnemyController;
	class EnemyService
	{
	private:
		EnemyController* enemyController;

	public:
		EnemyService();
		~EnemyService();

		void Initialize();
		void Update();
		void Render();

	};
}

