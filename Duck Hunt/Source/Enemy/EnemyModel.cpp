#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
	EnemyModel::EnemyModel()
	{

	}

	EnemyModel::~EnemyModel()
	{

	}
	void EnemyModel::Initialize()
	{
		enemyPosition = referencePosition;
	}

	void EnemyModel::Update()
	{

	}

	sf::Vector2f EnemyModel::GetEnemyPosition()
	{
		return enemyPosition;
	}

	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{

	}
}