#pragma once
#include <SFML/System/Vector2.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
	private:
		EnemyView* enemyView;
		EnemyModel* enemyModel;


	public:
		EnemyController();
		~EnemyController();

		void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
	};
}
