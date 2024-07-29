#pragma once
#include <SFML/System/Vector2.hpp>


namespace Enemy
{
	enum class EnemyType;
	class EnemyModel
	{
	private:
		sf::Vector2f referencePosition = sf::Vector2f(900.f, 880.f);
		sf::Vector2f enemyPosition;


	public:
		EnemyModel(EnemyType type);
		~EnemyModel();

		void Initialize();
		

		sf::Vector2f GetEnemyPosition();
		void SetEnemyPosition(sf::Vector2f position);

		const sf::Vector2f LeftMostPosition = sf::Vector2f(50.f, 50.f);
		const sf::Vector2f RightMostPosition = sf::Vector2f(1800.f, 50.f);
		const sf::Vector2f TopMostPosition = sf::Vector2f(960.f, 0.f);
		const sf::Vector2f BottomMostPosition = sf::Vector2f(950.f,880.f);

		EnemyType currentEnemyType;
		EnemyType GetCurrentEnemyType();

		static int NumberOfEnemies;
		static int enemiesKilled;
		static int enemyCount;


		
	};
}