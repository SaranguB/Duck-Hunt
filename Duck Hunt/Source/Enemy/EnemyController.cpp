#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController(EnemyType type)
	{
		enemyView = new EnemyView();
		enemyModel = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete(enemyView);
		delete(enemyModel);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyView->Initialize(this);
	}

	void EnemyController::Update()
	{
		enemyView->Update();
		Move();
		HandleOutOfBounds();
	}

	void EnemyController::HandleOutOfBounds()
	{
		sf::Vector2f enemyPosition = GetEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow()->getSize();

		if (enemyPosition.x<0 || enemyPosition.x >windowSize.x ||
			enemyPosition.y<0 || enemyPosition.y >windowSize.y)
		{

		}

	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();;
	}

	MovementDirection EnemyController::GetRandomMovementDirection()
	{
		int randomType = std::rand() % 8;
		return static_cast<Enemy::MovementDirection>(randomType);
		
	}

	sf::Sprite& EnemyController::GetEnemySprite()
	{
		
		return enemyView->GetEnemySprite();
	}

	EnemyType EnemyController::GetEnemyType()
	{
		return enemyModel->GetCurrentEnemyType();
	}
	
}