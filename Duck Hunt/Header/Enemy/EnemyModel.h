#pragma once
#include <SFML/System/Vector2.hpp>


namespace Enemy
{
	class EnemyModel
	{
	private:
		sf::Vector2f referencePosition = sf::Vector2f(0,0);
		sf::Vector2f enemyPosition;

	public:
		EnemyModel();
		~EnemyModel();

		void Initialize();
		void Update();

		sf::Vector2f GetEnemyPosition();
		void SetEnemyPosition(sf::Vector2f position);
		
	};
}