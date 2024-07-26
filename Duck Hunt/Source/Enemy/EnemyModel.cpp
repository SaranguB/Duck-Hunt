#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{
	}

	EnemyModel::~EnemyModel()
	{

	}
	void EnemyModel::Initialize()
	{
		enemyPosition = referencePosition;
	}


	sf::Vector2f EnemyModel::GetEnemyPosition()
	{
		return enemyPosition;
	}

	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}
	
}